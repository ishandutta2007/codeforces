#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1<<20|1,mod=1e9+7;
char st[N];
int n,ans,a[N];
V check(int&x){x-=mod,x+=x>>31&mod;}
I f(int x){return 1<<__builtin_popcount(x);}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
V FWT(int*a,int l){
	for(int i=1,x,y;i<l;i<<=1)for(int j=0,d=i<<1;j<l;j+=d)FOR(k,0,i-1)
		x=a[j|k],y=a[i|j|k],check(a[j|k]=x+y),check(a[i|j|k]=x+mod-y);
}
V mul(int*a,int x,int l,int*c){while(l--)*c++=1ll*x**a++%mod;}
V dot(int*a,int*b,int l,int*c){while(l--)*c++=1ll**a++**b++%mod;}
V IFWT(int*a,int l){FWT(a,l),mul(a,Pow(l,mod-2),l,a);}
int main(){
	scanf("%d%s",&n,st),n=1<<n;
	FOR(i,0,n-1)a[i]=st[i]-'0';
	FWT(a,n),dot(a,a,n,a),IFWT(a,n);
	FOR(i,0,n-1)check(ans+=1ll*f(i^n-1)*a[i]%mod);
	return cout<<3ll*ans%mod,0;
}