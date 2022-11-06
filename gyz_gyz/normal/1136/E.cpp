#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 300010
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,s0[N];
ll a[N],b[N],ls[N],lz[N],rs[N];
void dw(int x,int L,int R){
	if(!lz[x])return;int m=(L+R)>>1;
	lz[x<<1]=lz[x<<1|1]=ls[x<<1]=ls[x<<1|1]=rs[x<<1]=rs[x<<1|1]=lz[x];
	a[x<<1]=lz[x]*(m-L+1);a[x<<1|1]=lz[x]*(R-m);lz[x]=0;
}
void f(int x,int y,int z,int L,int R){
	if(y==L&&ls[x]+z>=rs[x]){
		ls[x]+=z;lz[x]=rs[x]=ls[x];
		a[x]=ls[x]*(R-L+1);return;
	}
	int m=(L+R)>>1;dw(x,L,R);
	if(y<=m){
		f(x<<1,y,z,L,m);
		if(rs[x<<1]>ls[x<<1|1])
			f(x<<1|1,m+1,rs[x<<1]-ls[x<<1|1],m+1,R);
	}else f(x<<1|1,y,z,m+1,R);
	ls[x]=ls[x<<1];rs[x]=rs[x<<1|1];
	a[x]=a[x<<1]+a[x<<1|1];
}
ll q(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return a[x];
	int m=(L+R)>>1;dw(x,L,R);
	if(r<=m)return q(x<<1,l,r,L,m);
	else if(l>m)return q(x<<1|1,l,r,m+1,R);
	else return q(x<<1,l,m,L,m)+q(x<<1|1,m+1,r,m+1,R);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&s0[i]);
	ll mx=-s0[1];
	rep(i,2,n){int x;
		scanf("%d",&x);
		b[i]=b[i-1]+x;
		mx=max(mx,b[i]-s0[i]);
	}
	rep(i,1,n)b[i]-=mx;
	dep(i,n,1)f(1,i,s0[i]-b[i],1,n);
	rep(i,2,n)b[i]+=b[i-1];
	scanf("%d",&m);
	rep(i,1,m){
		string s;cin>>s;
		int x,y;scanf("%d%d",&x,&y);
		if(s[0]=='s')printf("%lld\n",q(1,x,y,1,n)+b[y]-b[x-1]);
		else f(1,x,y,1,n);
	}
}