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
int a[1000005];
int vis[1000005];
int main(){
	n=read();
	int down=1000000000;
	int up=-1000000000;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=up&&a[i]>=down)
		{
			puts("NO");
			return 0;
		}
		if(a[i]>up&&a[i]<down)
		{
			if(a[i]<a[i+1])vis[i]=0,up=a[i];
			else down=a[i],vis[i]=1;
			continue;
		}
		if(a[i]>up)
		{
			vis[i]=0;
			up=a[i];
		}
		else 
		{
			vis[i]=1;
			down=a[i];
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
	return 0;
}