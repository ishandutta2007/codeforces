#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
const int mod=998244353;
int fac[N],ifac[N],pw2[N];
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
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
}
inline int C(int n,int m){
	if(n<0||m<0||n<m)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;	
}
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	init(n<<1);
	int la=0,lb=0,ra=0,rb=0;
	bool ok=0,ok1=1,ok2=1;
	int jb=0;
	for(int i=1;i<=n;++i){
		static string s;
		cin>>s;
		if(s[0]=='?')++la;
		else if(s[0]=='W')++lb;
		if(s[1]=='?')++ra;
		else if(s[1]=='B')++rb;	
		if(s[0]==s[1]){
			if(s[0]=='?')++jb;
			else ok=1;
		}
		if(s[0]=='W'||s[1]=='B')ok1=0;
		if(s[0]=='B'||s[1]=='W')ok2=0;
	}
	int ans=0;
	for(int i=0;i<=n;++i){
		ans=(ans+1LL*C(la,i-lb)*C(ra,i-rb))%mod;
	}
	if(!ok){
		ans=(ans+mod-pw2[jb])%mod;
		if(ok1)ans=(ans+1)%mod;
		if(ok2)ans=(ans+1)%mod;	
	}
	cout<<ans<<'\n';
	return 0;
}