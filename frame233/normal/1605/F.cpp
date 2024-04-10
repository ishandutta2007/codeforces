#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=85;int mod;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int dp[N][N],pw[N],C[N][N],D[N][N],inv[N],B[N][N];
inline ll binom(int n,int m){
	int ans=1;for(int i=0;i<m;++i)ans=1LL*ans*(n-i)%mod;
	for(int i=1;i<=m;++i)ans=1LL*ans*inv[i]%mod;
	return ans;
}
int calc(int m,int n){
	int ans=0;
	for(int i=0;i<=m;++i){
		int tmp=1LL*C[m][i]*binom(pw[m-i]-1,n)%mod;
		i&1?sub(ans,tmp):add(ans,tmp);
	}
	return ans;
}
int main(){
	int n,b;read(n,b,mod);
	for(int i=0;i<N;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	for(int i=0;i<N;++i){D[i][0]=1;for(int j=1;j<=i;++j)D[i][j]=1LL*D[i][j-1]*(i-j+1)%mod;}
	inv[0]=inv[1]=1;for(int i=2;i<N;++i)inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=2LL*pw[i-1]%mod;
	dp[0][0]=1;
	for(int i=0;i<=n;++i)for(int j=0;j<=b;++j)B[i][j]=calc(j,i);
	for(int i=1;i<=n;++i){
		for(int j=0;j<=b;++j)dp[i][j]=ksm(pw[j],i);
		for(int j=b;j>=0;--j){
			int s=0;
			for(int k=0;k<=j;++k){
				int tmp=1LL*C[j][k]*dp[i][k]%mod;
				(j-k)&1?sub(s,tmp):add(s,tmp);
			}
			dp[i][j]=s;
		}
		for(int j=0;j<=b;++j){
			for(int k=0,ed=i==n&&i%2?i-1:i;k<ed;++k){
				int sum=0;
				for(int l=0,coef=1;l<=j;++l){
					int tmp=1ULL*dp[k][l]*coef%mod*C[j][l]%mod*B[i-k][j-l]%mod;
					add(sum,tmp),coef=1ULL*coef*pw[i-k]%mod;
				}
				sub(dp[i][j],1LL*sum*D[i][i-k]%mod);
			}
		}
	}
	int ans=0;for(int i=0;i<=b;++i)add(ans,1LL*dp[n][i]*C[b][i]%mod);
	printf("%d\n",ans);
	return 0;
}