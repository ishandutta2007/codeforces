#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
typedef long long ll;
const ll mod=1000000007;
template<class T>
inline T read(){
	T x=0,f=1;
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
int n,m;
ll a[N],c[N+101][101],s[105][N];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main(){
	//freopen("kotori.in","r",stdin);
	//freopen("kotori.out","w",stdout);
	n=read<int>(),m=read<int>();
	for(int i=1;i<=n;i++){
		a[i]=read<ll>()%mod;
	}
	for(int i=0;i<=n;i++){
		c[i][0]=1;
	}
	for(int i=1;i<=n+100;i++){
		for(int j=1;j<=100;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j]+mod)%mod;
		}
	}
	for(int i=1;i<=m;i++){
		int l=read<int>(),r=read<int>(),k=read<int>();
		s[k+1][l]++;
		s[k+1][l]%=mod;
		for(int j=1;j<=k+1;j++){
			s[j][r+1]-=c[k+1-j+r-l][k+1-j];
			s[j][r+1]+=mod;
			s[j][r+1]%=mod;
		}
	}
	for(int k=100;k>=0;k--){
		ll cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=s[k+1][i];
			cnt%=mod;
			s[k][i]+=cnt;
			s[k][i]%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=(a[i]+s[0][i])%mod;
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}