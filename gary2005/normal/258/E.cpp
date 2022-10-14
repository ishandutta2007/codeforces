/*
{By GWj
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
const int MAXN=1e5+10,N=1<<18;
int n,m,in[MAXN],out[MAXN],rest[MAXN],cnt;
vector<int> g[MAXN],v[MAXN];
struct node{
	int mi,num,lazy;
}tree[N*2];
void push_up(int index){
	if(tree[index<<1].mi==tree[index<<1|1].mi){
		tree[index].mi=tree[index<<1].mi;
		tree[index].num=tree[index<<1].num+tree[index<<1|1].num;
	}
	else{
		if(tree[index<<1].mi<tree[index<<1|1].mi){
			tree[index]=tree[index<<1];
		}
		else{
			tree[index]=tree[index<<1|1];
		}
	}
}
void push_down(int index){
	tree[index].mi+=tree[index].lazy;
	if(index<N){
		tree[index<<1].lazy+=tree[index].lazy;
		tree[index<<1|1].lazy+=tree[index].lazy;
	}
	tree[index].lazy=0;
}
void add(int a,int b,int val=1,int now=1,int l=1,int r=N+1){
	push_down(now);
	if(r<=a||l>=b){
		return;
	}
	if(r<=b&&l>=a){
		tree[now].lazy+=val;
		push_down(now);
		return ;
	}
	int mid=(l+r)>>1;
	add(a,b,val,now<<1,l,mid);
	add(a,b,val,now<<1|1,mid,r);
	push_up(now);
}
mp query(int a,int b,int now=1,int l=1,int r=N+1){
	push_down(now);
	if(r<=a||l>=b){
		return II(INF,0);
	}
	if(r<=b&&l>=a){
		return II(tree[now].mi,tree[now].num);
	} 
	int mid=(l+r)>>1;
	mp L,R;
	L=query(a,b,now<<1,l,mid);
	R=query(a,b,now<<1|1,mid,r);
	if(L.FIR!=R.FIR){
		return min(L,R);
	}
	L.SEC+=R.SEC;
	return L;
}
void dfs(int now,int pre=0){
	in[now]=++cnt;
	for(auto it:g[now]){
		if(it!=pre){
			dfs(it,now);
		}
	}
	out[now]=++cnt;
}
void go(int now,int pre=0){
	for(auto it:v[now]){
		add(in[it],out[it]+1);
	}
	for(auto it:g[now]){
		if(it!=pre)
		go(it,now);
	}
	mp res=query(1,2*n+1);
	if(res.FIR!=0) res.SEC=0;
	rest[now]=(2*n-res.SEC)/2;
	for(auto it:v[now]){
		add(in[it],out[it]+1,-1);
	}
}
int main(){
	fastio;
	R2(n,m);
	rb(i,1,n-1){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u); 
	}
	rl(i,2*N-1,1)
	{
		if(i>=N){
			tree[i]=node{0,1,0};
		}
		else{
			tree[i]=node{0,tree[i<<1].num*2,0};
		}
	}
	dfs(1);
	rb(i,1,m){
		int a,b;
		R2(a,b);
		v[a].PB(b);
		v[a].PB(a);
		v[b].PB(a);
		v[b].PB(b);
	}
	go(1);
	rb(i,1,n){
		cout<<max(0,rest[i]-1)<<" ";
	}
	return 0;
}