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
char c[200005];
int pre[200005];
int nex[200005];
int main(){
//	freopen("a.in","r",stdin);
	int T;
	T=read();
	while(T--)
	{
		scanf("%s",c+1);
		c[0]=' ';
		int n=strlen(c)-1;
		c[n+1]=' ';
		if(n==1)
		{
			puts("1");
			continue;
		}
		for(int i=0;i<=n+1;i++)
		{
			pre[i]=i-1;
			nex[i]=i+1;
		}
		nex[0]=1;
		nex[n]=n+1;
		pre[n+1]=n;
		int now=n;
		now=pre[now];
		while(now!=0)
		{
			if(c[now]=='A'&&c[nex[now]]=='B')
			{
				nex[pre[now]]=nex[nex[now]];
				pre[nex[nex[now]]]=pre[now];
			}
			now=pre[now];
		}
		now=pre[n+1];
		int ans=0;
		while(now!=0)
		{
			ans++;
			if(c[now]=='B'&&c[nex[now]]=='B')
			{
				nex[pre[now]]=nex[nex[now]];
				pre[nex[nex[now]]]=pre[now];
				ans-=2;
			}
			now=pre[now];
		}
		printf("%d\n",ans);
	}
	return 0;
}