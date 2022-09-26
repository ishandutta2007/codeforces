#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
const int mx=100000;
const int mod=998244353;
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
int n,a[N],f[N],ans;
bool ntp[N];
int pn,p[N],mu[N];
void init(int n){
	ntp[1]=mu[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=i,mu[i]=-1;
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=true;
			if(i%p[j]==0)break;
			mu[p[j]*i]=-mu[i];
		}
	}
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
vector<int> vec[N];
void Split(int o){
	int x=a[o];
	for(int i=1;i*i<=x;++i){
		if(x%i==0){
			vec[i].push_back(o);
			if(i*i!=x)vec[x/i].push_back(o);
		}
	}
}
int main(){
	n=read();
	init(mx);
	for(int i=1;i<=n;++i){
		a[i]=read(),f[i]=read();
		Split(i);
	}
	for(int i=1;i<=mx;++i){
		int sum=0,tot1=0,tot2=0;
		bool ok1=false,ok2=false;
		for(auto u:vec[i]){
			sum=(sum+1LL*a[u]*f[u])%mod;
			if(tot2+f[u]>=2)ok1=true;
			if(tot2+f[u]>=3)ok2=true;
			tot1=(tot1+f[u])%(mod-1);
			tot2=(tot2+f[u])%mod;
		}
		if(!ok1)continue;
		int p1=qpow(2,tot1-2+mod-1),p2=1LL*(tot2-1+mod)%mod*qpow(2,tot1-2+mod-1)%mod;
		int tmp1=0,tmp2=0;
		if(ok2)p1=(p1+1LL*(tot2-2)*qpow(2,tot1-3+mod-1))%mod;
		for(auto u:vec[i]){
			tmp1=(tmp1+1LL*f[u]*a[u]%mod*(sum-a[u]))%mod;
			tmp2=(tmp2+1LL*f[u]*a[u]%mod*a[u])%mod;
		}
		ans=(ans+(1LL*p1*tmp1+1LL*p2*tmp2)*mu[i])%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}