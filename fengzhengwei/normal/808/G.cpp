#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
char c[100005];
char s[100005];
int f[2][100005];
int aut[100005][27];
int nxt[100005];
int n,m;
void pre()
{
	int p=0;
	for(int i=2;i<=m;i++)
	{
		while(p&&s[p+1]!=s[i])p=nxt[p];
		if(s[p+1]==s[i])p++;
		nxt[i]=p;
	}
	s[m+1]='=';
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(s[i+1]==j+'a')aut[i][j]=i+1;
			else aut[i][j]=aut[nxt[i]][j];
		}
	}
}
signed main(){
//	cout<<(-1&1)<<endl;
	scanf("%s",c);
	scanf("%s",s+1);
	s[0]=']';
	m=strlen(s)-1;
	memset(f,-0x3f,sizeof(f));
	f[1][0]=0;
	n=strlen(c);
	pre();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=m;j++)f[i&1][j]=-2147483647;
		if(c[i]=='?')
		{
			for(int j=0;j<=m;j++)
			{
				for(int k=0;k<26;k++)
				f[i&1][aut[j][k]]=max(f[i&1][aut[j][k]],f[(i-1)&1][j]);
			}
			f[i&1][m]++;
		}
		else 
		{
			for(int j=0;j<=m;j++)f[i&1][aut[j][c[i]-'a']]=max(f[i&1][aut[j][c[i]-'a']],f[(i-1)&1][j]);
			f[i&1][m]++;
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++)
	{
		ans=max(ans,f[(n-1)&1][i]);
	}
	cout<<ans<<endl;
	return 0;
}