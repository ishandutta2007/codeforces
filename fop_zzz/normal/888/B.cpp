#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int n,tot[2001];
char s[2001];
int main()
{
	n=read();
	scanf("\n%s",s+1);
	For(i,1,n)	tot[s[i]]++;
	int ans=min(tot['L'],tot['R'])+min(tot['U'],tot['D']);
	cout<<ans*2<<endl;
}