#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 270000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,k,kk,m;
struct pr{int l,r;}a[16][N*2];
pr operator +(pr x,pr y){
	return {min(x.l,y.l),max(x.r,y.r)};
}
pr q(int t,int x,int l,int r,int L,int R){
	if(l<=L&&r>=R)return a[t][x];int rr=(L+R)/2;
	if(r<=rr)return q(t,x*2,l,r,L,rr);
	if(l>rr)return q(t,x*2+1,l,r,rr+1,R);
	return q(t,x*2,l,r,L,rr)+q(t,x*2+1,l,r,rr+1,R);
}
void f(int t,int x,int y,int z,int L,int R){
	if(L==R){a[t][x]={z,z};return;}int rr=(L+R)/2;
	if(y<=rr)f(t,x*2,y,z,L,rr);else f(t,x*2+1,y,z,rr+1,R);
	a[t][x]=a[t][x*2]+a[t][x*2+1]; 
}
void tcg(int x){int a[5];
	rep(i,0,k-1)scanf("%d",&a[i]);
	rep(t,0,kk){int y=a[0];
		rep(j,0,k-2)if((t>>j)&1)y+=a[j+1];else y-=a[j+1];
		f(t,1,x,y,1,n);
	}
}
int main(){
	scanf("%d%d",&n,&k);kk=(1<<(k-1))-1;
	rep(i,1,n)tcg(i);
	scanf("%d",&m);
	rep(i,1,m){int op;
		scanf("%d",&op);
		if(op==1){int x;
			scanf("%d",&x);tcg(x);
		}else{int ans=0,l,r;
			scanf("%d%d",&l,&r);
			rep(t,0,kk){
				pr x=q(t,1,l,r,1,n);
				ans=max(ans,x.r-x.l);
			}
			printf("%d\n",ans);
		}
	}
}