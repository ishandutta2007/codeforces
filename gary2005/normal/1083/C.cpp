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
const int MAXN=200000+20;
const int MAXL=19;//1<<MAXL >= MAXN*2-2
class LCA{
	int id[MAXN],depth[MAXN],cnt=0,euler_tour[MAXN<<1],lg[MAXN<<1];
	mp st_table[MAXN<<1][MAXL+2];
	vector<int> g[MAXN];
	void dfs(int now,int pre=0,int deep=0){
		euler_tour[++cnt]=now;
		id[now]=cnt;
		depth[now]=deep;
		bool ok=true;
		for(auto it:g[now]){
			if(it!=pre){
				if(!ok){
					euler_tour[++cnt]=now;
				}
				ok=0;
				dfs(it,now,deep+1);
			}
		}
	}
	public: 
	inline void add_edge(int u,int v){
		g[u].PB(v);
		g[v].PB(u);
	}
	public:
	void pre_work(){
		dfs(1);//assume that 1 is root
		rb(i,1,cnt){
			st_table[i][0]=II(depth[euler_tour[i]],euler_tour[i]);
		}
		rb(i,1,MAXL)
			rb(j,1,cnt-(1<<i)+1){
				st_table[j][i]=min(
				st_table[j][i-1],
				st_table[j+(1<<i)-1-(1<<(i-1))+1][i-1]
				);
			}
		rb(i,1,cnt)
		{
			int j;
			for(j=0;(1<<j)<=i;j++); 
			lg[i]=j-1;
		}
	}
	public:
	int lca(int u,int v){
		int l,r;
		l=min(id[u],id[v]);
		r=max(id[u],id[v]);
		int len=r-l+1;
		int lgg=lg[len];
		mp best=min(st_table[l][lgg],st_table[r-(1<<lgg)+1][lgg]);
		return best.SEC;
	}
	public:
	bool ancient(int u,int v){//uv 
		return lca(u,v)==u;
	}
}lca;
struct node{
	bool can;//
	int a,b;// 
	inline node operator + (node B){
		node A={can,a,b};
		if(!A.can||!B.can) return node{0,0,0};
		vector<int> v;
		v.PB(A.a);
		v.PB(A.b);
		v.PB(B.a);
		v.PB(B.b);
		sort(ALL(v));
		v.erase(unique(ALL(v)),v.end());
		int Lca=lca.lca(v[0],v[1]);
		Lca=lca.lca(Lca,v[2]);
		Lca=lca.lca(Lca,v[3]);
		rep(i,v.size())
			rep(j,v.size()){
					int lca_=lca.lca(v[i],v[j]);
					if(
					(lca_!=v[i]&&lca_!=v[j]&&lca_!=Lca)
					)
					{
						return node{0,0,0};
					}
			} 
		rep(i,v.size())
			rep(j,v.size()){
				if(i==j) continue;
				bool ok=1;
				rep(k,v.size()){
					if(j==k||k==i) continue;
					if(
					(!lca.ancient(v[k],v[i])&&!lca.ancient(v[k],v[j]))
					)
					{
						ok=0;
						break;
					}
				}
				if(ok){
					return node{1,v[i],v[j]};
				}
			} 
//		cout<<"!\n";
//		for(auto it:v){
//			cout<<it<<' ';
//		}
//		cout<<endl<<Lca<<' '<<lca.lca(4,5)<<endl;
//		cout<<endl;
//		assert(0);
		return node{0,0,0};
	} 
};
int n,is[MAXN],p[MAXN],q;
const int N=1<<18;
struct SEGMENT_TREE{
	node tree[N+N];
	SEGMENT_TREE(){
		fill(tree+1,tree+N+N,node{0,0,0});
	}
	void modify(int index,int to){// 
		index+=N-1;
		tree[index]={1,to,to};
		index>>=1;
		while(index){
			tree[index]=tree[index<<1]+tree[index<<1|1];
			index>>=1;
		}
	}
	int binary_search(int now=1,int l=1,int r=N+1,node pre=node{0,0,0}){
		if(l==r-1){
			node now_=tree[now];
			if(l!=1) now_=now_+pre;
			if(now_.can) 
				return l;
				return 0;	
		}
		node Left=tree[now<<1];
		if(l!=1)
			Left=Left+pre;
		int mid=(l+r)>>1;
		if(Left.can){
			return max(mid-1,binary_search(now<<1|1,mid,r,Left)); 
		}
		return binary_search(now<<1,l,mid,pre);
	}
}sgt; 
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&p[i]),p[i]++;
	rb(i,1,n) is[p[i]]=i;
	rb(i,2,n){
		int di;
		scanf("%d",&di);
		lca.add_edge(di,i);
	}
	lca.pre_work();
	node test=node{1,1,1}+node{1,3,3};
//	cout<<test.can<<' '<<test.a<<' '<<test.b<<endl;
//	return 0;
	rb(i,1,n)
		sgt.modify(i,is[i]);
	int q;
	scanf("%d",&q); 
	while(q--){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			int i,j;
			scanf("%d%d",&i,&j);
			swap(p[i],p[j]);
			sgt.modify(p[i],i);
			sgt.modify(p[j],j); 
		}
		else{
//			cout<<sgt.tree[N>>2].can<<' '<<sgt.tree[N>>2].a<<" "<<sgt.tree[N>>2].b<<endl;
			printf("%d\n",sgt.binary_search());
		}
	}
	return 0;
}
/** 
  * lcaO(1) 
  * merge   merge
  	
	 - 4lcaab
	 - u(a,b,c,d),a->lca/b->lcaab
	 
  * 
  *
  **/