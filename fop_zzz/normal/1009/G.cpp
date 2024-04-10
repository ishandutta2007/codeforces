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

const int N=200005;
int sum[N][65],h[N][7],zt[N],cnt[10],ans[N],n;
char s[N],ts[N];
inline void out(int x)
{
	int q[10]={0},top=0;
	while(x)	q[++top]=x&1,x/=2;
	For(i,1,6)	cout<<q[i]<<' ';cout<<endl;	
}
inline bool check(int zt,int p)
{
	For(i,0,(1<<6)-1)
	if((i&zt)==i)
	{
		int ned=0,hav=sum[n][i]-sum[p-1][i];
		For(j,0,5)	if((1<<j)&i)	ned+=cnt[j];
//		if(p==5){out(zt);out(i);cout<<p<<' '<<ned<<' '<<hav<<endl;}
		if(ned>hav)	return 0;
	}
	return 1;
}
int main()
{
	scanf("\n%s",s+1);
	n=strlen(s+1);
	int len=n;
	For(i,1,len)	cnt[s[i]-'a']++;
	int m=read();
	For(i,1,m)
	{
		int p=read();
		scanf("\n%s",ts+1);int len=strlen(ts+1);
		For(j,1,len)	zt[p]|=(1<<(ts[j]-'a'));
	}
	For(i,1,n)	if(!zt[i])	zt[i]=(1<<6)-1;
//	For(i,1,n)	out(zt[i]);
	int mx=(1<<6)-1;
	For(j,1,n)
		For(i,0,mx)
		{
			sum[j][i]=sum[j-1][i]; 
			if((zt[j]&i)!=0)	sum[j][i]++;
//			if(j==1)	cout<<sum[j][i]<<'-'<<sum[j-1][i]<<' '<<(zt[j]&i)<<endl;
		}
	int now=0;
	For(i,0,5)	if(cnt[i])	now|=(1<<i);
//	cout<<sum[n][56]<<' '<<(zt[5]&56)<<' '<<zt[5]<<endl;
	For(i,1,n)
	{
		bool ok=0;
		For(j,0,5)
		if(cnt[j]&&(zt[i]&(1<<j)))
		{
			cnt[j]--;
			if(cnt[j]==0)	now^=(1<<j);
			if(check(now,i+1))
			{
				ans[i]=j;
				ok=1;
				break;
			}
			cnt[j]++;
			if(cnt[j]==1)	now^=(1<<j);
		}
		if(!ok)	{puts("Impossible");return 0;}
	}
	For(i,1,n)	putchar(ans[i]+'a');
}