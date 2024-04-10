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
const int xx=2e5+5;
int n,k;
char s[xx];
int f[xx][17],g[(1<<17)];
bool check(int x)
{
	for(int j=0;j<k;j++)
	{
		f[n+2][j]=n+1;
		f[n+1][j]=n+1;
		int tt=0;
		for(int i=n;i>=1;i--)
		{
			if(s[i]=='a'+j||s[i]=='?')tt++;
			else tt=0;
			if(tt>=x)f[i][j]=i+x-1;
			else f[i][j]=f[i+1][j];
		}
	}
	memset(g,0x3f,sizeof(g));
	g[0]=1;
	for(int i=0;i<(1<<k);i++)
		for(int j=0;j<k;j++)if(!(i>>j&1))g[i+(1<<j)]=min(g[i+(1<<j)],f[g[i]][j]+1);
	return g[(1<<k)-1]!=n+2;
}
signed main(){
	n=read(),k=read();
	scanf("%s",s+1);
	int l=0,r=n,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}