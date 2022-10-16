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
int n,m;
const int xx=1005;
char s[xx][xx];
int up[xx][xx];// 
ll ans[xx][xx];
int ss[xx][xx];// 
signed main(){
//	freopen("a.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			while((s[i][j]=getchar())>'z'||s[i][j]<'a');
			if(s[i][j]==s[i-1][j])up[i][j]=up[i-1][j];
			else up[i][j]=i;
//			cout<<i<<" "<<j<<" sss "<<up[i][j]<<"\n";
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int now=i;
			int v[3];
			for(int k=0;k<3;k++)
			{
				v[k]=now-up[now][j]+1;
				now=up[now][j]-1;
				if(!now&&k!=2)
				{
					ss[i][j]=-1; 
					break;
				}
			}
//			cout<<i<<" "<<j<<" "<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<now<<"\n";
			if(ss[i][j]!=-1&&v[0]==v[1]&&v[1]<=v[2])ss[i][j]=v[0];// 
			else ss[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int last=0;
		for(int j=1;j<=m;j++)
		{
			ans[i][j]=ans[i][j-1]+ans[i-1][j]-ans[i-1][j-1];
			if(ss[i][j]==-1||ss[i][j]!=ss[i][j-1]||s[i][j]!=s[i][j-1]||s[i-ss[i][j]][j]!=s[i-ss[i][j]][j-1]||s[i-2*ss[i][j]][j]!=s[i-2*ss[i][j]][j-1])last=0;
			if(ss[i][j]!=-1)last++;
			ans[i][j]+=last;
//			cout<<i<<" "<<j<<" "<<last<<"\n";
		}
	}
	cout<<ans[n][m]<<'\n';
	return 0;
}