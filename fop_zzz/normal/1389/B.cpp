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

int n,k,z,ans,a[200005],step,sum[200005];
priority_queue<pa,vector<pa>,less<pa> > q;
inline int Solve(int x)
{
	int tmp=0;
	int kk=k,zz=z;
	// For(i,2,x+1)	tmp+=a[i],kk--;	
	tmp+=sum[x+1];kk-=x;
	// while(kk>=2&&zz)
	// {
	// 	tmp+=a[x]+a[x+1];
	// 	kk-=2;zz--;
	// }
	int times=min(kk/2,zz);
	tmp+=times*(a[x]+a[x+1]);
	kk-=times*2;zz-=times;
	int pos=x+1,epos=pos+kk-1;
	tmp+=sum[epos]-sum[pos];
	// while(kk>1){pos++;tmp+=a[pos];kk--;}
	if(a[epos+1]<a[epos-1]&&zz)	tmp+=a[epos-1];else	tmp+=a[epos+1];
	// int pos=x+1;
	// while(kk>1){pos++;tmp+=a[pos];kk--;}
	// if(kk)	if(a[pos+1]<a[pos-1]&&zz)	tmp+=a[pos-1];else	tmp+=a[pos+1];
//	cout<<x<<' '<<tmp<<endl;
	return tmp;	
}
signed main()
{
	int t=read();
	while(t--)
	{
		n=read();k=read();z=read();
		ans=0;
		For(i,1,n)	a[i]=read();
		For(i,1,n)	sum[i]=sum[i-1]+a[i];
		For(i,1,k)
		{
			ans=max(ans,Solve(i));
		}
		writeln(ans);
	}
}