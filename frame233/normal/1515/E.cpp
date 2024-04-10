#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=405;
int dp[N][N],mod,pw[N],C[N][N];
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int main(){
	int n;read(n,mod);
	for(int i=0;i<N;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=pw[i-1],add(pw[i],pw[i]);
	dp[0][0]=1;for(int i=0;i<n;++i)for(int j=0;j<=i;++j)for(int k=i+1;k<=n;++k)add(dp[k+1][j+k-i],1ULL*dp[i][j]*pw[k-i-1]%mod*C[j+k-i][j]%mod);
	int ans=0;for(int i=0;i<=n;++i)add(ans,dp[n+1][i]);
	printf("%d\n",ans);
	return 0;
}