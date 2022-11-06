#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
bool check[2000002];int prime[2000002],f[2000005];
int main()
{
	memset(check,0,sizeof(check));
	int tot=0;
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(!check[i])
		{
			prime[tot++]=i;
			f[i]=i;
		}
		for(int j=0;j<tot;j++)
		{if(i*prime[j]>n)
		break;
		check[i*prime[j]]=true;
		f[i*prime[j]]=f[i]; 
		if(i%prime[j]==0)
		break;
		}
	}
	int maxx=0;
	for(int i=n;i;i--)
	{
		if(n%i==0&&!check[i])
		{
			maxx=i;
			break;
		}
	}
	//cout<<maxx;
	int ans=n;
	for(int i=n-maxx+1;i<=n;i++)
	{
		//cout<<i<<" "<<f[i]<<endl;
		if(check[i])
		ans=min(ans,i-f[i]+1);
	}
	cout<<ans;
}