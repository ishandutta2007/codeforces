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

const int N=500005;
int ans[N],a[N],cnt[N],n;
int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		For(i,1,n)	ans[i]=0,cnt[i]=0;
		For(i,1,n)	a[i]=read(),cnt[a[i]]++;
		bool quan=1;
		For(i,1,n)	if(cnt[i]>1)	quan=0;
		if(quan)	ans[1]=1;
		if(cnt[1])	ans[n]=1;
		int l=1,r=n,now=1;
		Dow(i,2,n-1)
		{
			if(cnt[now+1]&&cnt[now]==1&&(a[l]==now||a[r]==now))
			{
				ans[i]=1;
				if(a[l]==now)	l++;else	r--;
				++now;
			}	else	break;
		}
		For(i,1,n)	printf("%d",ans[i]);puts("");
	}
}