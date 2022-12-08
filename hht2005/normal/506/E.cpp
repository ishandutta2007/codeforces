#include<bits/stdc++.h>
using namespace std;
const int N=310,mod=10007;
char s[N];
int dp[N][N][N],g[N],n,m,k;
int h(int i,int l,int r) {
	if(i<0)return 0;
	if(l==1&&r==m)return !i;
	if(~dp[i][l][r])return dp[i][l][r];
	dp[i][l][r]=0;
	if(l>1&&s[l-1]!=s[r])dp[i][l][r]+=h(i-1,l-1,r);
	if(r<m&&s[l]!=s[r+1])dp[i][l][r]+=h(i-1,l,r+1);
	if(1<l&&r<m&&s[l-1]==s[r+1])dp[i][l][r]+=h(i,l-1,r+1);
	return dp[i][l][r]%=mod;
}
int tas[N][N],f[N],t[N][N];
void mul1() {
	memset(t,0,sizeof(t));
	for(int l=1;l<=k;l++)
		for(int j=1;j<=k;j++)
			t[1][j]=(t[1][j]+1ll*f[l]*tas[l][j])%mod;
	for(int i=1;i<=k;i++)
		f[i]=t[1][i];
}
void mul2() {
	memset(t,0,sizeof(t));
	for(int i=1;i<=k;i++)
		for(int l=1;l<=k;l++)
			for(int j=1;j<=k;j++)
				t[i][j]=(t[i][j]+1ll*tas[i][l]*tas[l][j])%mod;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			tas[i][j]=t[i][j];
}
void qpow(int b) {
	while(b) {
		if(b&1)mul1();
		mul2();
		b>>=1;
	}
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%s",s+1);
	m=strlen(s+1);
	k=m+((m+1)>>1);
	scanf("%d",&n);
	int g=0,ans=0;
	for(int i=0;i<m;i++) {
		int c=0;
		for(int j=1;j<=m;j++) {
			c+=h(i,j,j);
			if(j<m&&s[j]==s[j+1])c+=h(i,j,j+1);
		}
		if(i)tas[k-(m-i-1)/2-1][i]=c%mod;
		else g=c%mod;
	}
	for(int i=2;i<m;i++)tas[i][i-1]=1;
	for(int i=m;i<k;i++)tas[i+1][i]=1;
	for(int i=1;i<m;i++)tas[i][i]=24;
	for(int i=m;i<k;i++)tas[i][i]=25;
	tas[k][k]=26;
	f[k]=1;
	qpow((n+m-1)/2+1);
	if(m>1)ans+=f[1];
	ans+=g*f[m];
	if((n+m)%2==0) {
		printf("%d\n",ans%mod);
		return 0;
	}
	memset(tas,g=0,sizeof(tas));
	memset(f,0,sizeof(f));
	for(int i=0;i<m;i++) {
		int c=0;
		for(int j=1;j<=m;j++)
			if(j<m&&s[j]==s[j+1])c+=h(i,j,j+1);
		if(i)tas[k-(m-i-1)/2-1][i]=c%mod;
		else g=c%mod;
	}
	for(int i=2;i<m;i++)tas[i][i-1]=1;
	for(int i=m;i<k;i++)tas[i+1][i]=1;
	for(int i=1;i<m;i++)tas[i][i]=24;
	for(int i=m;i<k;i++)tas[i][i]=25;
	f[k]=1;
	qpow((n+m-1)/2+1);
	if(m>1)ans-=f[1];
	ans-=g*f[m];
	ans=(ans%mod+mod)%mod;
	printf("%d\n",ans);
	return 0;
}