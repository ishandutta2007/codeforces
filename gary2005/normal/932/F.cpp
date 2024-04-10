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
struct line{
	LL k,b;
	line (){
		k=0;
		b=1e18;
	}
	line (LL A,LL B){
		k=A;
		b=B;
	}	
};
const int N=1<<18;
LL get(LL x,line L){
	x-=1e5+1;
	return L.k*x+L.b;
}
vector<int> undo;
struct LiChao_Tree{
	line tree[N+N];
	void modify(line L,int now=1,int l=1,int r=N+1){
		undo.PB(now);
		line tmp=tree[now];
		int mid=(l+r)>>1;
		if(l==r-1){
			if(get(mid,tree[now])>get(mid,L)){tree[now]=L;}
			return;
		}
		if(tree[now].k<L.k){
			if(get(mid,L)<get(mid,tree[now])){
				tree[now]=L;
				modify(tmp,now<<1|1,mid,r);
			}
			else{
				modify(L,now<<1,l,mid);
			}
		}
		else{
			if(tree[now].k>L.k){
				if(get(mid,L)<get(mid,tree[now])){
					tree[now]=L;
					modify(tmp,now<<1,l,mid);
				}
				else{
					modify(L,now<<1|1,mid,r);
				}
			}
			else{
				if(tree[now].b>L.b) tree[now]=L;
			}
		}
	}
	LL query(int x){
		int xx=x;
		x+=N-1;
		LL rest=1e18;
		while(x){
			check_min(rest,get(xx,tree[x]));
			x>>=1;	
		}
		return rest;
	}
}tree;
int n;
int a[100000+20],b[100000+20];
void undo_(){
	for(auto it:undo){
		tree.tree[it]=line(0,1e18);
	}
	undo.clear();
}
vector<int> g[100000+20];
int siz[100000+20];
LL dp[100000+20];
int heavy[100000+20];
void run(int now,int pre){
	siz[now]=1;
	for(auto it:g[now]){
		if(it!=pre){
			run(it,now);
			if(heavy[now]==0||siz[it]>siz[heavy[now]]) heavy[now]=it;
			siz[now]+=siz[it];
		}
	}
}
void add(int id){
	tree.modify(line(b[id],dp[id]));
}
vector<int> dfs(int now,int pre){
	vector<int> ret;
	for(auto it:g[now]){
		if(it!=pre&&it!=heavy[now]){
			vector<int> tmp=dfs(it,now);
			for(auto it:tmp)
				ret.PB(it);
			undo_(); 
		}
	}
	if(heavy[now]){
		vector<int> tmp=dfs(heavy[now],now);
		for(auto it:ret){
			add(it);
			tmp.PB(it);
		}
		dp[now]=tree.query(a[now]+1e5+1);
		add(now);
		tmp.PB(now);
		return tmp;
	}
	ret.PB(now);
	dp[now]=0;
	add(now);
	return ret;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);		
	}	
	rb(i,1,n)
		scanf("%d",&b[i]);
	rb(i,2,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u); 
	}
	run(1,0);
	dfs(1,0);
	rb(i,1,n) printf("%lld ",dp[i]);	
	return 0;
}