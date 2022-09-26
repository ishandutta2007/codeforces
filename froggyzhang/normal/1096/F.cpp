#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200010
typedef long long ll;
const int mod=998244353;
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
int n,a[N],k,vis[N],b[N],ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
struct BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void Add(int x,int d){
		while(x<=n){
			b[x]+=d;
			x+=lowbit(x);
		}
	}
	inline int Ask(int x){
		int ans=0;
		while(x){
			ans+=b[x];
			x-=lowbit(x);
		}
		return ans;
	}
}B;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=n;i>=1;--i){
		if(~a[i]){
			vis[a[i]]=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(!vis[i])b[++k]=i;
	}
	for(int i=1,now=0;i<=n;++i){
		if(~a[i]){
			int t=upper_bound(b+1,b+k+1,a[i])-b-1;
			ans=(ans+1LL*t*(k-now)+1LL*(k-t)*now)%mod;
		}
		else{
			++now;
		}
	}
	ans=1LL*ans*qpow(k,mod-2)%mod;
	ans=(ans+1LL*k*(k-1)%mod*qpow(4,mod-2))%mod;
	for(int i=n;i>=1;--i){
		if(~a[i]){
			ans=(ans+B.Ask(a[i]))%mod;
			B.Add(a[i],1);
		}
	}
	printf("%d\n",ans);
	return 0;
}