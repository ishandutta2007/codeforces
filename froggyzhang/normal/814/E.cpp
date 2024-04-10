#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 303
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;
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
int n,d[N],f[N][N][N],dp[N][N],ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		d[i]=read();
	}
	f[0][0][0]=1;
	for(int i=0;i<=n;++i){
		for(int c2=0;c2<=n;++c2){
			for(int c1=0;c1<=n;++c1){
				if(!c1&&!c2)continue;
				int &now=f[i][c1][c2];
				if(c2){
					if(i>1)now=(now+1LL*f[i-2][c1][c2-1]*(i*(i-1)/2))%mod;
					if(i&&c2>1)now=(now+1LL*f[i-1][c1+1][c2-2]*i*(c2-1))%mod;
					if(c2>2)now=(now+1LL*f[i][c1+2][c2-3]*((c2-1)*(c2-2)/2))%mod;
					if(c2>1&&c1)now=(now+1LL*f[i][c1][c2-2]*c1*(c2-1))%mod;
					if(i&&c1)now=(now+1LL*f[i-1][c1-1][c2-1]*c1*i)%mod;
					if(c1>1)now=(now+1LL*f[i][c1-2][c2-1]*(c1*(c1-1)/2))%mod;
				}
				else{
					if(i)now=(now+1LL*f[i-1][c1-1][c2]*i)%mod;
					if(c1>1)now=(now+1LL*f[i][c1-2][c2]*(c1-1))%mod;
				}
			}
		}
	}
	dp[n+1][n]=1;
	for(int l=n;l>=2;--l){
		for(int r=l;r<=n;++r){
			int d1=0,d2=0;
			for(int i=l;i<=r;++i){
				if(d[i]==2)++d1;
				else ++d2;
			}
			for(int k=0;k<=2*d2+d1&&r+k<=n;++k){
				dp[l][r]=(dp[l][r]+1LL*dp[r+1][r+k]*f[k][d1][d2])%mod;
			}
		}
	}
	printf("%d\n",d[1]+1>n?0:dp[2][d[1]+1]);
	return 0;
}