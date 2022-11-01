#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
#define inf 1e17
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int n,k,t[201],in[201],ans[201],tot;
inline void check(int dis)
{
	For(i,1,k)
		if((t[i]-1)/dis+1!=in[i])	return;
	ans[++tot]=(n-1)/dis+1;
}
int main()
{
	n=read();k=read();
	For(i,1,k)
		t[i]=read(),in[i]=read();
	For(i,1,100)
		check(i);
	int t=ans[1];
	For(i,1,tot)	if(t!=ans[i])	{puts("-1");return 0;}
	cout<<t<<endl;
}