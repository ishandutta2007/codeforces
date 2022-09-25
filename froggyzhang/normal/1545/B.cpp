#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int T,n,inv[N];
char s[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void Solve(){
	n=read();
	scanf("%s",s+1);
	int now=0,sum=0;
	for(int i=1;i<=n+1;++i){
		if(i>n||s[i]=='0'){
			sum-=now&1,now=0;
		}
		else ++now,++sum;
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
	sum>>=1;
	int cnt=0;
	for(int i=1;i<=n;++i){
		cnt+=s[i]=='0';
	}
	int ans=1;
	for(int i=1;i<=sum+cnt;++i){
		ans=1LL*ans*i%mod;
	}
	for(int i=1;i<=sum;++i){
		ans=1LL*ans*inv[i]%mod;
	}
	for(int i=1;i<=cnt;++i){
		ans=1LL*ans*inv[i]%mod;
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}