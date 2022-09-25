#include<bits/stdc++.h>
using namespace std;
#define N 21
typedef long long ll;
const int mod=31607;
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
int n,p[N][N],a[N],b[N],ip[N][N],X,Y,cnt[1<<N],ans;
int z[N][1<<N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
const int inv10000=qpow(10000,mod-2);
int main(){
	n=read();
	for(int i=0;i<n;++i)a[i]=b[i]=1;
	for(int i=1;i<(1<<n);++i)cnt[i]=cnt[i>>1]+(i&1);
	X=Y=1;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			p[i][j]=1LL*read()*inv10000%mod;
			ip[i][j]=qpow(p[i][j],mod-2);
			a[i]=1LL*a[i]*p[i][j]%mod;
			b[j]=1LL*b[j]*p[i][j]%mod;
		}
	}
	for(int i=0;i<n;++i)X=1LL*X*p[i][i]%mod;
	for(int i=0;i<n;++i)Y=1LL*Y*p[i][n-1-i]%mod;
	for(int i=0;i<n;++i){
		for(int j=0;j<(1<<n);++j){
			z[i][j]=1;
			for(int k=0;k<n;++k){
				if(j>>k&1){
					z[i][j]=1LL*z[i][j]*ip[k][i]%mod;
				}
			}	
		}	
	}
	for(int tx=0;tx<=1;++tx){
		for(int ty=0;ty<=1;++ty){
			for(int i=0;i<(1<<n);++i){
				int P=(cnt[i]+tx+ty)&1?1:mod-1;
				for(int k=0;k<n;++k){
					if(i>>k&1)P=1LL*P*a[k]%mod;
				}
				if(tx)P=1LL*P*X%mod;
				if(ty)P=1LL*P*Y%mod;
				for(int j=0;j<n;++j){
					int A=P,B=mod-P;
					if(tx&&ty&&n&1&&j==(n>>1)&&!(i>>(n>>1)&1))A=1LL*A*ip[j][j]%mod;
					B=1LL*B*b[j]%mod*z[j][i]%mod;
					if(tx){
						if(i>>j&1)A=1LL*A*ip[j][j]%mod;
						B=1LL*B*ip[j][j]%mod;
					}
					if(ty){
						if(i>>(n-j-1)&1)A=1LL*A*ip[n-j-1][j]%mod;
						B=1LL*B*ip[n-j-1][j]%mod;
					}
					P=(A+B)%mod;
				}
				ans=(ans+P)%mod;
			}
		}
	}
	printf("%d\n",(ans+1)%mod);
	return 0;
}