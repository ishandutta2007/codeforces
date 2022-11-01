#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<cmath>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
char s[10000001];
ll len,hsh[2000001][11],bas=10;

ll mo[4] = {1000000007, 1000000009, 998244353, 1000000037};
inline ll ksm1(ll x,ll y,ll m){ll sum=1;for(;y;y/=2){if(y&1)	sum=sum*x%m;x=x*x%m;}	return sum;}
inline ll ksm(ll x,ll y){ll sum=1;for(;y;y/=2){if(y&1)	sum=sum*x;x=x*x;}	return sum;}
inline ll get(int l,int r,int k)
{
	ll t=0,ret=0;
	if(k==10) t=ksm(bas,r-l+1),ret=hsh[r][10]-t*hsh[l-1][10];
	else	t=ksm1(bas,r-l+1,mo[k]),ret=((hsh[r][k]-t*hsh[l-1][k])%mo[k]+mo[k])%mo[k];
	return ret;
}
int a1[2000001],a2[2000001],a3[2000001],a4[2000001],len1,len2,len3;
bool flag=0;
inline void solve(int x)
{
	int rest=len-x;
//	if(rest/2>(x-10))	return;	
	For(l,rest/2,rest/2+1)
	{
		if((get(1,x,10)+get(x+1,len-l,10))==get(len-l+1,len,10))
		{
			flag=1;
			For(i,0,3)	if(((get(1,x,i)+get(x+1,len-l,i))%mo[i]+mo[i])%mo[i]!=get(len-l+1,len,i)){flag=0;break;}
			if(!flag)	continue;
			if(s[1]=='0'&&x!=1)	continue;
			if(s[x+1]=='0'&&len-l!=x+1)	continue;
			if(s[len-l+1]=='0'&&len!=len-l+1)	continue;	
//			cout<<x<<' '<<len-l<<endl;
			For(i,1,x)	putchar(s[i]);
			putchar('+');
			For(i,x+1,len-l)	putchar(s[i]);
			putchar('=');
			For(i,len-l+1,len)	putchar(s[i]);
			exit(0);
		}
	}
	For(l,x,x+1)
	{
//		if(len-l<x+1)	continue;
		if((get(1,x,10)+get(x+1,len-l,10))==get(len-l+1,len,10))
		{
			flag=1;
			For(i,0,3)	if(((get(1,x,i)+get(x+1,len-l,i))%mo[i]+mo[i])%mo[i]!=get(len-l+1,len,i)){flag=0;break;}
			if(!flag)	continue;
			if(s[1]=='0'&&x!=1)	continue;
			if(s[x+1]=='0'&&len-l!=x+1)	continue;
			if(s[len-l+1]=='0'&&len!=len-l+1)	continue;
//			cout<<x<<' '<<len-l<<endl;
			For(i,1,x)	putchar(s[i]);
			putchar('+');
			For(i,x+1,len-l)	putchar(s[i]);
			putchar('=');
			For(i,len-l+1,len)	putchar(s[i]);	
			exit(0);
		}
	}

}
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%s",s+1);
	len=strlen(s+1);
	hsh[0][4]=0;
	For(i,1,len)	hsh[i][10]=hsh[i-1][10]*bas+s[i]-48;
	For(i,1,len)	For(j,0,3)		hsh[i][j]=(hsh[i-1][j]*bas+s[i]-48)%mo[j];
	For(i,1,len/2+1)	solve(i);
}