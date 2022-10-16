#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,k;
int a[1000005];
int t[104];
signed main(){
	int T=read();
	while(T--)
	{
		memset(t,0,sizeof(t));
		n=read();
		k=read();
		int ans=n+9;
		for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]=1;
		for(int i=1;i<=100;i++)
		{
			if(!t[i])continue;
			int tot=1;
			int res=0;
			while(tot<=n)
			{
				if(a[tot]!=i)
				{
					tot+=k;
					res++;
					tot--;
				}
				tot++;
			}
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}