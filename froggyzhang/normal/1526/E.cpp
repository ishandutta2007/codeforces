#include<bits/stdc++.h>
using namespace std;
#define N 400010
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
int n,k,inv[N],rk[N],cnt,p[N];
int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	int ans=1;
	for(int i=n;i>=n-m+1;--i)ans=1LL*ans*i%mod;
	for(int i=1;i<=m;++i)ans=1LL*ans*inv[i]%mod;
	return ans;
}
int main(){
    
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		rk[p[i]=read()]=i;
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
	rk[n]=-1;
	for(int i=1;i<n;++i)cnt+=rk[p[i]+1]>rk[p[i+1]+1];
	printf("%d\n",C(n+k-1-cnt,n));
	return 0;
}