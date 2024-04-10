#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<map>
#include<algorithm>
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define eps 1e-8
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
struct node{ll H,S;}	p[200001];
inline bool cmp(node x,node y){return x.S*y.H>y.S*x.H;}
ll n,ans,len;
char s[200001];
int main()
{
	n=read();
	For(i,1,n)
	{
		scanf("\n%s",s+1);
		len=strlen(s+1);
		ll now=0,tmp=0;
		For(j,1,len)
		{
			if(s[j]=='h')	tmp+=now,p[i].H++;
			else	now++,p[i].S++;
		}
		ans+=tmp;
	}
	sort(p+1,p+n+1,cmp);
	ll tmp=0;
	For(i,1,n)
	{
		ans+=p[i].H*tmp;
		tmp+=p[i].S;
	}
	cout<<ans<<endl;
}