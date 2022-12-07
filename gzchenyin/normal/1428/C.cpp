#include<cstdio>
#include<cstring>
using namespace std;
char s[200005];
int n,t,nxt[200005],lst[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++) nxt[i]=i+1,lst[i]=i-1;
		nxt[0]=1,lst[n+1]=n;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='A' || lst[i]==0) continue;
			nxt[lst[lst[i]]]=nxt[i];
			lst[nxt[i]]=lst[lst[i]];
		}
		int now=0,ans=0;
		while(now!=n+1)
		{
			now=nxt[now];
			ans++;
		}
		printf("%d\n",ans-1);
	}
}