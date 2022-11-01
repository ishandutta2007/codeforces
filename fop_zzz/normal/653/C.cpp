#pragma comment(linker, "/stack:200000000")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back


using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
const int N=2e5+5;
int a[N],b[5],gg1,gg2,n,ans,top,q[N];
const int inf=1e9;
inline int pd(int x)
{
//	if(x<0||x>n)	return 1;
	if(x&1)	if(a[x-1]<=a[x])	return 0;else	return 1;
	if(!(x&1))	if(a[x-1]>=a[x])	return 0;else	return 1;
}
inline int ky(int x,int y)
{
	int tmp=0;
	swap(a[x],a[y]);
	tmp=pd(x)+pd(y);
	if(x+1!=y)	tmp+=pd(x+1);if(y+1!=x)	tmp+=pd(y+1);
	swap(a[x],a[y]);
	tmp-=pd(x)+pd(y);
	if(x+1!=y)	tmp-=pd(x+1);if(y+1!=x)	tmp-=pd(y+1);
	return tmp;
}
map<int,int> mp[N];
int main()
{
	a[0]=-1;
	n=read();
	if(n&1)	a[n+1]=-1;else	a[n+1]=0;
	For(i,1,n)	a[i]=read();
	For(i,1,n-1)
	{
		if(i&1)	if(a[i]>=a[i+1])	q[++top]=i;
		if(!(i&1))	if(a[i]<=a[i+1])	q[++top]=i;
	}
	if(top>4)	return puts("0"),0;
	For(i,1,n)	if((!pd(i))||(!pd(i+1)))
	{
		For(j,1,n)
		{
			if(j==i||mp[i][j])	continue;
//			cout<<top<<' '<<i<<' '<<j<<' '<<ky(i,j)<<endl;
			if(ky(i,j)==top)	mp[i][j]=mp[j][i]=1,ans++;//cout<<i<<' '<<j<<endl;
		}		
	}
	writeln(ans);
} 
 /*
 10
7 7 8 10 5 10 1 5 2 6
 */