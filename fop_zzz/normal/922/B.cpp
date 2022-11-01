#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<map>
#include<algorithm>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
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
int ans,n,a[4],b[4];
int main()
{
	n=read();
	For(i,1,n)
		For(j,i+1,n)
		{
			int k=i^j;
			if(k<j||k>n)	continue;
			if(i+j>k)	ans++;//cout<<i<<' '<<j<<' '<<k<<endl;
		}
	cout<<ans<<endl;
}