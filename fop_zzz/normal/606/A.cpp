#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(register int i=j;i<=k;++i)
#define Dow(i,j,k)	for(register int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=(t*10+c-48),c=getchar();
	return t*f;
}
int a1,a2,a3,b1,b2,b3,sum;
int main()
{
	a1=read();a2=read();a3=read();
	b1=read();b2=read();b3=read();
	if(a1>b1)	sum+=(a1-b1)/2;
	else	sum+=(a1-b1);
	if(a2>b2)	sum+=(a2-b2)/2;
	else	sum+=(a2-b2);
	if(a3>b3)	sum+=(a3-b3)/2;
	else	sum+=(a3-b3);
	if(sum>=0)	cout<<"Yes";else cout<<"No";
}