/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int u[500000+20],v[500000+20];
const int N=1<<20;
vector<int> g[500000+20];
struct RUN{
	int root,cnt,in[500000+20],out[500000+20],tree[N+N][2];
	bool tag[N+N];
	void dfs(int now,int pre,int deep=0){
		in[now]=++cnt;
		tree[N+cnt-1][0]=deep;
		for(auto it:g[now]){
			if(it!=pre){
				dfs(it,now,deep+1);
			}
		}
		out[now]=++cnt;
		tree[N+cnt-1][0]=deep;
	}
	void work(){
		rl(i,N-1,1){
			tree[i][0]=max(tree[i<<1][0],tree[i<<1|1][0]);
		}
	}
	void push_down(int index){
		if(!tag[index]) return;
		swap(tree[index][0],tree[index][1]);
		if(index<N)
			tag[index<<1]^=1,tag[index<<1|1]^=1;
		tag[index]=0;
	}
	void push_up(int index){
		assert(index<N);
		assert(!tag[index]);
		tree[index][0]=max(tree[index<<1][0],tree[index<<1|1][0]);
		tree[index][1]=max(tree[index<<1][1],tree[index<<1|1][1]);
	}
	void modify_(int a,int b,int now=1,int l=1,int r=N+1){
		push_down(now);
		if(r<=a||l>=b){
			return;
		}
		if(r<=b&&l>=a){
			tag[now]^=1;
			push_down(now);
			return;
		}
		int mid=(l+r)>>1;
		modify_(a,b,now<<1,l,mid);
		modify_(a,b,now<<1|1,mid,r);
		push_up(now);
	}
	RUN(int x){
		memset(tag,0,sizeof(tag));
		memset(tree,0,sizeof(tree));
		root=x;
		cnt=0;
		dfs(root,0);
		work();
	}
	inline void modify(int u,int v){
		if(in[u]<in[v]);
		else swap(u,v);
//		cout<<"__"<<in[v]<<' '<<out[v]<<' '<<v<<endl;
		modify_(in[v],out[v]+1);
	}
	inline int query(){
		return tree[1][0];
	}
};
mp best;
void dfs(int now,int pre,int dis=0){
	check_max(best,II(dis,now));
	for(auto it:g[now]){
		if(it!=pre){
			dfs(it,now,dis+1);
		}
	}
}
int main(){
	scanf("%d",&n);
	vector<int> V;
	rb(i,1,n-1){
		int t;
		scanf("%d%d%d",&u[i],&v[i],&t);
		g[u[i]].PB(v[i]);
		g[v[i]].PB(u[i]);
		if(t==1){
			V.PB(i); 
		}
	}
	best=II(-1,-1);
	dfs(1,0);
	int x=best.second;
	best=II(-1,-1);
	dfs(x,0);
	int y=best.second;
//	cout<<x<<' '<<y<<endl;
	static RUN t1(x);
	static RUN t2(y);
	for(auto it:V){
		t1.modify(u[it],v[it]);
		t2.modify(u[it],v[it]);
	}
	int m;
	scanf("%d",&m);
	while(m--){
		int z;
		scanf("%d",&z);
		t1.modify(u[z],v[z]);
		t2.modify(u[z],v[z]);
//		printf("%d--%d\n",t1.query(),t2.query());
		printf("%d\n",max(t1.query(),t2.query()));
	}
	return 0;
}