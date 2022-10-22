#include <bits/stdc++.h>
const int inv=3973,mod=31607;
using namespace std;
int T,n,m,s[21][2100000],f[2100000];
char sz[2100010];
void qmo(int &x){
	x+=(x>>31)&mod;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		s[i][0]=1;
		for(int j=0,w;j<n;j++) scanf("%d",&w),s[i][1<<j]=1ll*w*inv%mod;
		for(int j=0;j<(1<<n);j++) s[i][j]=1ll*s[i][j&-j]*s[i][j^(j&-j)]%mod;
	}
	for(int S=0;S<(1<<n);S++) sz[S]=sz[S>>1]+(S&1);
	int res=1; 
	for(int T=0;T<4;T++){
		for(int S=0;S<(1<<n);S++) f[S]=(sz[S]+sz[T])&1?mod-1:1;
		for(int i=0;i<n;i++) for(int S=0;S<(1<<n);S++){
			f[S]=1ll*f[S]*(s[i][S|(T&1)<<i|((T>>1)&1)<<(n-1-i)]-s[i][(1<<n)-1]+mod)%mod;
		}
		for(int S=0;S<(1<<n);S++) qmo(res-=f[S]);
	} 
	printf("%d\n",res);
}