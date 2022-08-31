#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
#define ll long long
#define lb(x) (x&(-x))
using namespace std;
int n,f[1048576],s[1048576],L[1048576];
bool g[1048576];
ll a[22],S[1048576];
inline ll Abs(re ll x){return x>0?x:-x;}
inline void gmx(re int &x,re int y){(y>x)&&(x=y);}
int main(){
	L[0]=-1,scanf("%d",&n);for(re int i=0;i<n;++i){scanf("%lld",&a[i]);if(!a[i])--i,--n;}
	for(re int i=1;i<(1<<n);++i)L[i]=L[i>>1]+1,S[i]=S[i^lb(i)]+a[L[lb(i)]],s[i]=s[i^lb(i)]+1;
	for(re int i=1;i<(1<<n);++i)
		if(S[i]-s[i]&1)
		for(re int j=i&(i-1);j>(i>>1);j=(j-1)&i)
			if(Abs(S[j]-S[i^j])<s[i]){f[i]=g[i]=1;break;}
	for(re int i=1;i<(1<<n);++i){
		re int B=((1<<n)-1)^i;
		if(g[i])for(re int j=B;j;j=(j-1)&B)gmx(f[i^j],f[j]+1);
	}
	printf("%d",n-f[(1<<n)-1]);
}