#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=5e5+5;
int n,a[N],linc[N],ldec[N],rinc[N],rdec[N];
int q[N],top;
inline bool ok(int l,int r)
{
	return (l==r)&&(r%2);
}
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)
	{
		if(i==1||i==n||1LL*(a[i-1]-a[i])*(a[i]-a[i+1])<0)
			q[++top]=i;
	}
	int len=0;
	For(i,2,top)	len=max(len,q[i]-q[i-1]);
	int num=0;
	For(i,2,top)	if(len==q[i]-q[i-1])	++num;
	// cout<<num<<' '<<len<<endl;
	if(num!=2||(len%2))	puts("0");
		else
		{
			For(i,2,top)
				if(q[i]-q[i-1]==len&&q[i+1]-q[i]==len&&(a[q[i]]-a[q[i-1]]>0))
				{
					puts("1");
					exit(0);
				}
			puts("0");
		}

}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	-- Benq
*/