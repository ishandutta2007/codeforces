#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<ctime>
#include<algorithm>
#define For(i,j,k)  for(register int i=j;i<=k;++i)
#define Dow(i,j,k)  for(register int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
#define eps 1e-8
#define pa pair<ll,ll>
#define fir first
#define sec second
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
int n,k,a[201],ans=1e9;
int main()
{
	n=read();k=read();
	For(i,1,n)	a[i]=read();
	sort(a+1,a+n+1);
	For(i,1,n)
		For(j,i,n)
			if(a[j]-a[i]<=k)	ans=min(ans,i-1+(n-j));
	cout<<ans<<endl;
}