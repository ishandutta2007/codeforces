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
		b=-1e18;
	}
	line (LL A,LL B){
		k=A;
		b=B;
	}	
};
const int N=1<<18;
LL get(LL x,line L){
	return L.k*x+L.b;
}
struct LiChao_Tree{
	line tree[N+N];
	void init(){
		rb(i,1,N+N-1)
		{
			tree[i].k=0;
			tree[i].b=-1e18;
		}
	}
	void modify(line L,int now=1,int l=1,int r=N+1){
		line tmp=tree[now];
		int mid=(l+r)>>1;
		if(l==r-1){
			if(get(mid,tree[now])<get(mid,L)){tree[now]=L;}
			return;
		}
		if(tree[now].k<L.k){
			if(get(mid,L)>get(mid,tree[now])){
				tree[now]=L;
				modify(tmp,now<<1,l,mid);
			}
			else{
				modify(L,now<<1|1,mid,r);
			}
		}
		else{
			if(tree[now].k>L.k){
				if(get(mid,L)>get(mid,tree[now])){
					tree[now]=L;
					modify(tmp,now<<1|1,mid,r);
				}
				else{
					modify(L,now<<1,l,mid);
				}
			}
			else{
				if(tree[now].b<L.b) tree[now]=L;
			}
		}
	}
	LL query(int x){
		int xx=x;
		x+=N-1;
		LL rest=-1e18;
		while(x){
			check_max(rest,get(xx,tree[x]));
			x>>=1;	
		}
		return rest;
	}
}tree,tree2;
int n;
int a[200000+20];
LL sum[200000+20];
int main(){
	scanf("%d",&n);
	rb(i,1,n)
		scanf("%d",&a[i]);
	rb(i,1,n)
		sum[i]=sum[i-1]+a[i];
	LL rest=0;
	rb(i,2,n){
		tree.modify(line(a[i-1],sum[i-1]+1ll*a[i-1]*(-i+1)));
		check_max(rest,tree.query(i)-sum[i]);
	}
	rl(i,n-1,1){
		tree2.modify(line(a[i+1],sum[i]+1ll*a[i+1]*(-i-1)));
		check_max(rest,tree2.query(i)-sum[i-1]);
	}
	rb(i,1,n)
		rest+=1ll*i*a[i];
	cout<<rest<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/