#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
ll m;
const int xx=1e5+5;
int to[xx][26];
unsigned ll f[105][105];
unsigned ll sum[105];
char s[xx];
int main(){
	n=read();
	cin>>m;
	scanf("%s",s+1);
	for(int j=0;j<26;j++)to[n][j]=1e5+1;
	for(int i=n-1;i>=0;i--)
	{
		memcpy(to[i],to[i+1],sizeof(to[i+1]));
		to[i][s[i+1]-'a']=i+1;
	}
	f[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<26;k++)f[i+1][to[j][k]]+=f[i][j];
			sum[i]+=f[i][j];
		}
	}
	unsigned ll ans=0;
	for(int i=n;i>=0;i--)
	{
		if(sum[i]<m)ans+=sum[i]*(n-i),m-=sum[i];
		else 
		{
			ans+=m*(n-i);
			cout<<ans<<"\n";
			return 0;
		}
	}
	puts("-1");
	return 0;
}