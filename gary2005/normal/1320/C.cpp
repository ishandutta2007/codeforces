/*
AuThOr Gwj
*/
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define get(a) cin>>a
#define get2(a,b) cin>>a>>b
using namespace std;
const LL INF=1e17;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN= 200000+2;
int N=1;
struct segtree{
	LL tree[MAXN*8],add[MAXN*8];
	void init(int x=0){
		while(N<MAXN)
			N<<=1;
		if(x)
		rep(i,MAXN*8) add[i]=0,tree[i]=x;
		else 
		{
			memset(add,0,sizeof(add));
			memset(tree,0,sizeof(tree));
		}
	}
	LL query(int a,int b,int now=1,int l=1,int r=N+1){
		if(r<=a||l>=b){
			return -INF;
		}
		if(r<=b&&l>=a){
			return tree[now]+add[now];
		}
		int mid=(l+r)>>1;
		return max(query(a,b,now<<1,l,mid),query(a,b,(now<<1)+1,mid,r))+add[now];
	}
	LL inc(int a,int b,int val,int now=1,int l=1,int r=N+1){
		if(r<=a||l>=b){
			return tree[now]+add[now];
		}
		if(r<=b&&l>=a){
			add[now]+=val;
			return tree[now]+add[now];
		}
		int mid=(l+r)>>1;
		return (tree[now]=max(inc(a,b,val,now<<1,l,mid),inc(a,b,val,(now<<1)+1,mid,r)))+add[now];
	}	
}segt;
int n,m,p;
mp a[200000+20],b[200000+20];
pair<mp,int> c[200000+20];
void ud(int x,int y){
	if(x>=b[m].FIR) return;
	int l=1,r=m;
	while(l<r){
		int mid=(l+r)>>1;
		if(x>=b[mid].FIR){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	segt.inc(l,m+1,y);
}
int main(){
	fastio;
	segt.init();
	cin>>n>>m>>p;
	rb(i,1,n)
		get2(a[i].FIR,a[i].SEC);
	rb(i,1,m)
		get2(b[i].FIR,b[i].SEC);
	rb(i,1,p){
		get2(c[i].FIR.FIR,c[i].FIR.SEC);
		get(c[i].SEC);
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	sort(c+1,c+1+p);
	LL res=-INF;
	rb(i,1,m)
		segt.inc(i,i+1,-b[i].SEC);
	int is=1;
	rb(i,1,n){
		while(is<=p&&c[is].FIR.FIR<a[i].FIR){
			ud(c[is].FIR.SEC,c[is].SEC);
			is++;
		}
		res=max(res,segt.query(1,m+1)-a[i].SEC);
	} 
	cout<<res<<endl;
	return 0;
}