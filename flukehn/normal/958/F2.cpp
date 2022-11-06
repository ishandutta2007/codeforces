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
int num[200005],sum;
int a[200005],k[2000005];
int n,minn=1000000000,m;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) k[i]=read();
	for(int i=1;i<=m;i++)
	{
		if(k[i]==0) sum++;
	}
	int l=0,r=1;
	while(l<=n)
	{
		while(l+1>r-1&&r<=n)
		{
			num[a[r]]++;
			if(num[a[r]]==k[a[r]]) sum++;
			r++;
		}
		num[a[l]]--;
		if(num[a[l]]==k[a[l]]-1&&a[l]!=0) sum--;
		while(r<=n&&sum!=m)
		{
			num[a[r]]++;
			if(num[a[r]]==k[a[r]]) sum++;
			r++;
		}
		//cout<<l<<" "<<r<<" "<<sum<<endl;
		if(sum==m)
		{
			minn=min(minn,r-l-1);
		}
		l++;
	}
	int temp=0;
	for(int i=1;i<=m;i++)
	temp+=k[i];
	if(minn>n) puts("-1");
	else cout<<minn-temp;
}