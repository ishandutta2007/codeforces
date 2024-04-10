//by yjz
#include<bits/stdc++.h>
using namespace std;
char s[100111],t[100111];
int n,m,f[100111],A[100111],B[100111];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s",t+1);m=strlen(t+1);
	for(int i=2;i<=m;i++)
	{
		int &p=f[i];
		p=f[i-1];
		while(p&&t[p+1]!=t[i])p=f[p];
		p+=t[p+1]==t[i];
	}
	int *dp=A,*ndp=B;
	for(int i=1;i<=m;i++)dp[i]=-n;
	for(int i=1;i<=n;i++)
	{
		ndp[0]=dp[0];
		for(int j=0;j<=m;j++)
		{
			if(s[i]=='?'||t[j+1]==s[i])ndp[j+1]=dp[j];
			else ndp[j+1]=-n;
		}
		ndp[m]++;
		for(int j=m;j>=0;j--)ndp[f[j]]=ndp[f[j]]>ndp[j]?ndp[f[j]]:ndp[j];
		swap(dp,ndp);
	}
	cout<<dp[0]<<endl;
	return 0;
}