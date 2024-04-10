#include<cstdio>
#include<string>
#include<iostream>
#include<map>
#define For(i,j,k) for(register int i=j;i<=k;++i)
#define Dow(i,j,k) for(register int i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
map<string,int> mp;
int n;
string s;
int main()
{
	n=read();
	For(i,1,n)
	{
		cin>>s;
		if(mp[s])	puts("YES");else {puts("NO");mp[s]=1;}
	}
}