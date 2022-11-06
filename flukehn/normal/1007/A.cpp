#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
queue<int> q;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int a[100005],b[100005],n; 
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int pla=n+1;
	int l=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		while(l<=n)
		{
			if(a[l]>a[i])
			{
				ans++;
				l++;
				break;
			}
			else l++;
		}
	}
	cout<<ans;
}