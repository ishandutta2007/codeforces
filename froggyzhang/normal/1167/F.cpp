#include<bits/stdc++.h>
using namespace std;
#define N 500050
const int mod=1e9+7;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int a[N],n,p[N],rk[N];
int ans;
struct BIT{
	ll b[N];	
	void clear(){memset(b,0,sizeof(b));}
	inline int lowbit(int x){return x&(-x);}
	inline void Add(int x,int d){while(x<=n)b[x]+=d,x+=lowbit(x);}
	inline ll Ask(int x){ll ans=0;while(x)ans+=b[x],x-=lowbit(x);return ans;}
}B;
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),p[i]=i;
	sort(p+1,p+n+1,[&](int i,int j){return a[i]<a[j];});
	for(int i=1;i<=n;++i)rk[p[i]]=i;
	for(int i=1;i<=n;++i){
		ans=(ans+1LL*i*(n-i+1)%mod*a[i])%mod;
		ans=(ans+B.Ask(rk[i])%mod*a[i]%mod*(n-i+1))%mod;
		B.Add(rk[i],i);
	}
	B.clear();
	for(int i=n;i>=1;--i){
		ans=(ans+B.Ask(rk[i])%mod*a[i]%mod*i)%mod;
		B.Add(rk[i],n-i+1);	
	}
	printf("%d\n",ans);
	return 0;
}