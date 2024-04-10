#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
#define N 55
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,L[N],R[N],inv[N],d[N<<1],t[N<<1],dp[N][N<<1],ans;
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
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	}
}
inline int C(int n,int m){
	if(!m)return 1;
	if(n<0||m<0||n<m)return 0;
	int ans=1;
	for(int i=n;i>=n-m+1;--i){
		ans=1LL*ans*i%mod;
	}
	for(int i=1;i<=m;++i){
		ans=1LL*ans*inv[i]%mod;
	}
	return ans;
}
inline bool check(int l,int r,int x){
	for(int i=l;i<=r;++i){
		if(L[i]>d[x]||R[i]<=d[x-1])return false;
	}
	return true;
}
int main(){
	n=read();
	init(n);
	for(int i=1;i<=n;++i){
		d[i]=L[i]=read(),d[i+n]=R[i]=read();
		--d[i];
	}
	reverse(L+1,L+n+1);
	reverse(R+1,R+n+1);
	sort(d+1,d+(n<<1)+1);
	d[0]=-1;
	for(int i=1;i<=(n<<1);++i){
		t[i]=d[i]-d[i-1];
	}
	dp[0][0]=1;
	for(int i=0;i<=n;++i){
		for(int j=1;j<=(n<<1);++j){
			for(int k=0;k<=i;++k){
				if(check(k+1,i,j)){
					dp[i][j]=(dp[i][j]+1LL*C(t[j]+i-k-1,i-k)*dp[k][j-1])%mod;
				} 
			}
		}
	}
	ans=dp[n][n<<1];
	for(int i=1;i<=n;++i){
		ans=1LL*ans*qpow(R[i]-L[i]+1,mod-2)%mod;
	}
	printf("%d\n",ans);
	return 0;
}