#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll unsigned long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int a[100010],n,f[100010];
int main()
{
	n=read();
	For(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	For(i,1,n)
	{
		f[i]=1;
		for(int j=1;j<i;j++)if(a[i]==a[j])f[i]=max(f[i],f[j]+1);
	}
	int cnt=0;
	For(i,1,n)	cnt=max(cnt,f[i]);
	cout<<cnt<<endl; 
}