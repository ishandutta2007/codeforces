#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
#define INF 2000000000000000LL
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

ll f[2][10005];
ll s[10005];
ll p[10005];
int n;ll c;

int main()
{
	n=read();c=read();
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<=n;i++)s[i]=read();
	int nown=1,pre=0;
	for(int j=1;j<=n;j++)f[0][j]=f[1][j]=INF;	
	for(int i=1;i<=n;i++)
	{
		f[nown][0]=f[pre][0]+s[i];
		for(int j=1;j<=i;j++)
			f[nown][j]=min(f[pre][j-1]+p[i]+(i-j)*c,f[pre][j]+s[i]);
		nown=1-nown;pre=1-pre;
	}
	ll ans=INF;
	for(int i=0;i<=n;i++)
		ans=min(ans,f[pre][i]);
	cout<<ans;
	return 0;
}