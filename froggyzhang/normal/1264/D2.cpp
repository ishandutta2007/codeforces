#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define N 1000100
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
int n,fac[N],ifac[N],ans;
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
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;	
	}
}
inline int C(int n,int m){
	if(m>n||m<0||n<0)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;	
}
pair<int,int> L[N],R[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	init(n);
	for(int i=1;i<=n;++i){
		L[i].first=L[i-1].first+(s[i]=='(');
		L[i].second=L[i-1].second+(s[i]=='?');
	}
	for(int i=n;i>=1;--i){
		R[i].first=R[i+1].first+(s[i]==')');
		R[i].second=R[i+1].second+(s[i]=='?');
	}
	for(int i=1;i<=n;++i){
		int d=R[i+1].first+R[i+1].second-L[i].first;
		if(d>=0){
			ans=(ans+1LL*C(L[i].second+R[i+1].second,d)*L[i].first+1LL*C(L[i].second+R[i+1].second-1,d-1)*L[i].second)%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}