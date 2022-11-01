#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define Dow(i,j,k) for(int i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int ans=1e9,n,w[2001],q[2001];
inline bool cmp(int x,int y){return w[x]<w[y];}
inline void solve(int x,int y)
{
	int top=0;
	For(i,1,2*n)	if(i!=x&&i!=y)	q[++top]=i;
	sort(q+1,q+top+1,cmp);
	int tmp=0;
	For(i,1,top/2)
		tmp-=w[q[i*2-1]]-w[q[i*2]];
	ans=min(ans,tmp);
}
int main()
{
	n=read();
	For(i,1,2*n)	w[i]=read();
	For(i,1,2*n)
		For(j,i+1,2*n)
			solve(i,j);
	cout<<ans<<endl;
}