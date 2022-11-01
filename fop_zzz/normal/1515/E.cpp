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
const int N=200005;

int sum[3][405][405][2];
int n,mo,ans;
inline void Add(int &x,int y)
{
	x=x+y;
	if(x<0)	x+=mo;
	if(x>mo)	x-=mo;
} 
int main()
{
	// dp i j k i j  k(j)  i-1<i?  i-1<i  i+1>i 
//	dp[1][1][1][0]=1;
	sum[1][1][1][0]=1;
	n=read();mo=read();
	For(i,2,n)
		For(j,1,i)	
			For(k,1,j)
			{
				int ti=i%3;
				sum[ti][j][k][0]=sum[ti][j][k][1]=0;
				if(i>=2)	Add(sum[ti][j][k][0],sum[(ti+1)%3][j-1][j-1][1]),Add(sum[ti][j][k][0],sum[(ti+1)%3][j-1][j-1][0]);
				 
//				Add(dp[i][j][k][0],sum[i-1][j-1][j-1][1]-sum[i-1][j-1][k-1][1]);// ii-1 
				Add(sum[ti][j][k][0],sum[(ti+2)%3][j-1][j-1][0]-sum[(ti+2)%3][j-1][k-1][0]);// ii-1 
				Add(sum[ti][j][k][1],sum[(ti+2)%3][j-1][k-1][1]);
				Add(sum[ti][j][k][1],sum[(ti+2)%3][j-1][k-1][0]);
//				cout<<sum[ti][j][k][0]<<' '<<sum[ti][j][k][1]<<endl; 
				if(i==n)	Add(ans,sum[ti][j][k][0]),Add(ans,sum[ti][j][k][1]);
				sum[ti][j][k][0]=sum[ti][j][k-1][0]+sum[ti][j][k][0];
				if(sum[ti][j][k][0]>mo)	sum[ti][j][k][0]-=mo; 
				sum[ti][j][k][1]=sum[ti][j][k-1][1]+sum[ti][j][k][1];
				if(sum[ti][j][k][1]>mo)	sum[ti][j][k][1]-=mo;
			}
	cout<<ans<<endl;
}