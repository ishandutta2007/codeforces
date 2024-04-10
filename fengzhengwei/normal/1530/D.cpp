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
const int xx=200005;
int t[xx];
int b[xx],a[xx],vis[xx],vs[xx],n;
signed main(){
	int T=read();
	while(T--)
	{
		n=read();
		memset(t,0,sizeof(t[0])*(n+1));
		memset(b,0,sizeof(b[0])*(n+1));
		memset(vis,0,sizeof(vis[0])*(n+1));
		memset(vs,0,sizeof(vs[0])*(n+1));
		int res=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read(),t[a[i]]++,res+=t[a[i]]==1;
			if(t[a[i]]==1)b[i]=a[i],vis[a[i]]=1,vs[a[i]]=i;
		}
		cout<<res<<'\n';
//		for(int i=1;i<=n;i++)cout<<b[i]<<' ';puts("");
		int tt=1,rr=n;
		for(int i=1;i<=n;i++)
		{
			if(!b[i])
			{
				while(vis[tt])tt++;
				while(vis[rr])rr--;
//				cout<<i<<' '<<tt<<" "<<rr<<'\n';
				if(tt!=i)vis[tt]=1,b[i]=tt;
				else vis[rr]=1,b[i]=rr;
			}
		}
		for(int i=1;i<=n;i++)
		if(b[i]==i)swap(b[i],b[vs[a[i]]]);
		for(int i=1;i<=n;i++)cout<<b[i]<<' ';
		puts("");
	}
	return 0;
}