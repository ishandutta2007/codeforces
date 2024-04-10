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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e5+10;
const int root=1;
vector<pair<LL,LL> > segments;
vector<int> w[MAXN];
set<int> store;
vector<int> g[MAXN];
int point[MAXN],dfn[MAXN],fa[MAXN],Map[MAXN],heavy[MAXN],siz[MAXN],top[MAXN];
LL prefix_sum[MAXN];
struct HLD{
	int cnt=0;
	void dfs1(int now,int pre){
		siz[now]=1;
		fa[now]=pre;
		for(auto it:g[now]){
			if(it==pre) continue; 
			dfs1(it,now);
			siz[now]+=siz[it]; 
		}
		heavy[now]=0;
		for(auto it:g[now]){
			if(it==pre) continue;
			if(siz[heavy[now]]<siz[it])
				heavy[now]=it;
		}
	}
	void dfs2(int now,int pre){
		dfn[now]=++cnt;
		Map[cnt]=now;
		if(heavy[now]){
			top[heavy[now]]=top[now];
			dfs2(heavy[now],now);
		}
		for(auto it:g[now]){
			if(it==pre||it==heavy[now]) continue;
			top[it]=it;
			dfs2(it,now);
		}
	}
	void go(){
		dfs1(root,0);
		top[root]=root;
		dfs2(root,0);	
	}
}hld;
const int N=1<<17;
struct SEGMENT_TREE{
	int tag[N+N]={0};
	void push_down(int index){
		if(tag[index]){
			tag[index<<1]=tag[index<<1|1]=tag[index];
			tag[index]=0;	
		}
	}
	void all_set(int a,int b,int val,int now=1,int l=1,int r=N+1){
		if(a>=r||b<=l){
			return;
		}
		if(r<=b&&l>=a){
			tag[now]=val;
			return;
		}
		push_down(now);
		int mid=(l+r)>>1;
		all_set(a,b,val,now<<1,l,mid);
		all_set(a,b,val,now<<1|1,mid,r);
	}
	int get_num(int a){
		a+=N-1;
		int NUM=0;
		while(a){
			if(tag[a]) NUM=tag[a];
			a>>=1;
		}
		return NUM;
	}
}sgt;
void run(int s,int t){
	int reals=s;
	while(s){
		int l=dfn[top[s]],r=dfn[s]-1;
		auto ite=store.lower_bound(l);
		while(ite!=store.end()&&*ite<=r){
			LL l=sgt.get_num(*ite)+1;
			LL r=t;
			if(l!=1)
			l+=prefix_sum[Map[*ite]];
			r+=prefix_sum[Map[*ite]];
			segments.PB(II(l,r));
			point[Map[*ite]]=heavy[Map[*ite]];
			store.erase(ite++);
		}
		int MODIFY=fa[top[s]];	
		if(MODIFY){
			if(point[MODIFY]!=top[s]){
				LL l=sgt.get_num(dfn[MODIFY])+1;
				LL r=t;
				if(l!=1)
				l+=prefix_sum[MODIFY];
				r+=prefix_sum[MODIFY];
				segments.PB(II(l,r));
			}
			point[MODIFY]=top[s];
			store.insert(dfn[MODIFY]);
		}
		if(s!=reals)
		sgt.all_set(dfn[top[s]],dfn[s]+1,t);
		else
		if(top[s]!=s){
			sgt.all_set(dfn[top[s]],dfn[s],t);
		}
		s=fa[top[s]];
	}
}
int n,m; 
void go_for_prefix_sum(int now){
	rep(i,g[now].size()){
		prefix_sum[g[now][i]]+=prefix_sum[now];
		prefix_sum[g[now][i]]+=w[now][i];
		go_for_prefix_sum(g[now][i]);	
	}
}
int main(){
	fastio;
	R2(n,m);
	rb(i,2,n){
		int U,V,W;
		cin>>U>>V>>W;
		g[U].PB(V);
		w[U].PB(W); 
	}
	go_for_prefix_sum(root);
	hld.go();
	rb(i,1,n){
		if(!g[i].empty()){
			point[i]=g[i].back();
		}
		if(point[i]!=heavy[i])
			store.insert(dfn[i]);		
	}
	vector<mp> queries;
	rb(i,1,m){
		int si,ti;
		R2(si,ti);
		queries.PB(II(ti,si));
	}
	for(auto it:queries){
		run(it.SEC,it.FIR);
	}
	sort(ALL(segments));
	LL rest1=1000000000000000000ll;
	int rest2=0;
	LL nowt=0;
	multiset<LL> rs; 
	rep(i,segments.size()){ 
		check_max(nowt,segments[i].FIR);
		rs.insert(segments[i].SEC);
		LL NEX=1000000000000000000ll;
		if(i!=segments.size()-1)
			NEX=segments[i+1].FIR;
		while(nowt<NEX&&!rs.empty()&&nowt<=*rs.begin()){
			rs.erase(rs.begin());
			nowt++;	
		}
		if(!rs.empty()&&*rs.begin()<nowt){
			check_min(rest1,*rs.begin());
			rs.clear();
		}
	}	
	if(!rs.empty())
		check_min(rest1,*rs.begin());
	if(rest1==1000000000000000000ll) rest1=-1;
	if(rest1==-1) rest2=segments.size();
	else{
		for(auto it:segments)
			if(it.SEC<rest1)
				rest2++;
	}
	cout<<rest1<<' '<<rest2<<endl;
	return 0;
}