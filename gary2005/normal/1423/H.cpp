/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,Q,k;
struct DSU{
	int siz[100000+20],fa[100000+20];
	stack<pair<mp,mp> > sta;
	void undo(int x){
		rb(i,1,x){
			int u=sta.top().FIR.FIR,v=sta.top().FIR.SEC;
//			cout<<"Undo:"<<u<<' '<<v<<endl;
			int fat=sta.top().SEC.FIR;
			int si=sta.top().SEC.SEC;
			sta.pop();
			if(!u) continue;
			siz[v]=si;
			fa[u]=fat;
		}
	}
	int root(int x){
		return (fa[x]==x? x:root(fa[x]));
	} 
	void merge(int u,int v){
		if(root(u)==root(v)){
			sta.push(II(II(0,0),II(0,0)));
		}
		else{
			u=root(u);
			v=root(v);
			if(siz[u]>siz[v]) swap(u,v);
			sta.push(II(II(u,v),II(fa[u],siz[v])));
			fa[u]=v;
			siz[v]+=siz[u];
		}
	}
}dsu;
const int N=1<<19;
vector<mp> edges[N+N];
void modify(int a,int b,mp PP,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b) return ;
	if(r<=b&&l>=a){
		edges[now].PB(PP);
		return;
	}
	int mid=(l+r)>>1;
	modify(a,b,PP,now<<1,l,mid);
	modify(a,b,PP,now<<1|1,mid,r);
} 
int rest[500000+20];
vector<mp> q[N+1];
void dfs(int now,int l=1,int r=N+1){
	for(auto it:edges[now]){
//		cout<<"Merge:"<<it.FIR<<' '<<it.SEC<<endl;
		dsu.merge(it.FIR,it.SEC);
	}
	if(l==r-1){
		for(auto it:q[l]){
//			cout<<l<<" "<<it.FIR<<" "<<it.SEC<<endl; 
			rest[it.SEC]=dsu.siz[dsu.root(it.FIR)];
		}	
	}
	else{
		int mid=(l+r)>>1;
		dfs(now<<1,l,mid);
		dfs(now<<1|1,mid,r); 
	}
	dsu.undo(edges[now].size());
}
int main(){
	cin>>n>>Q>>k;
	rb(i,1,n) dsu.siz[i]=1,dsu.fa[i]=i;
	int d=1;
	fill(rest+1,rest+1+Q,-1);
	vector<pair<int,mp> > queries;
	rb(i,1,Q){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y;
			scanf("%d %d",&x,&y);
			queries.PB(II(t,II(x,y)));
//			modify(d,min(N+1,d+k),II(x,y));
		} 
		if(t==2){
			int x;
			scanf("%d",&x);
			queries.PB(II(t,II(x,0)));
//			q[d].PB(II(x,i));
		}
		if(t==3){
			queries.PB(II(t,II(0,0)));
			d++;
		}
	}
	deque<int> times=deque<int> (k,N);
	rl(i,Q-1,0){
		int t;
		t=queries[i].FIR;
		if(t==3){
			times.push_front(i+1);
			times.POB();
		}
		else{
			if(t==2){
				q[i+1].PB(II(queries[i].SEC.FIR,i+1));
			}
			else{
				modify(i+1,times.back()+1,II(queries[i].SEC.FIR,queries[i].SEC.SEC));
			}
		}
	}
	dfs(1,1,N+1);
	rb(i,1,Q){
		if(rest[i]>=0) printf("%d\n",rest[i]); 
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/