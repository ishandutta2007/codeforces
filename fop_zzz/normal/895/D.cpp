#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define inf 1e17
#define For(i,j,k)  for(register int i=j;i<=k;++i)
#define Dow(i,j,k)  for(register int i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') f=-1;c=getchar();}
    while(isdigit(c))   t=t*10LL+c-'0',c=getchar();
    return t*f;
}
inline void write(ll x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
ll mo=1e9+7,len;
inline ll ksm(ll x,int y){ll sum=1;for(;y;y/=2,x=x*x%mo)	if(y&1)	sum=sum*x%mo;return sum;}
char a[2000001],b[2000001];
ll fac[2000001],rev[2000001],ans,cnt[2001],ans1;
int main()
{
	scanf("\n%s",a+1);
	scanf("\n%s",b+1);
	len=strlen(a+1);
	For(i,1,len)	cnt[a[i]]++;
	fac[0]=1;For(i,1,len)	fac[i]=fac[i-1]*i%mo;
	rev[len]=ksm(fac[len],mo-2); 
	Dow(i,1,len-1)	rev[i]=(rev[i+1]*(i+1))%mo;
	rev[0]=1;
	For(pre,0,len)//pre
	{
		ll tmp=fac[len-pre-1];

		ll div=1;
		if(pre!=0)	
		{
			if(cnt[b[pre]])	cnt[b[pre]]--;
			else	break;
		}
		For(j,'a','z')	div*=rev[cnt[j]],div%=mo;
		For(j,'a',b[pre+1]-1)
			if(cnt[j])
			{
				cnt[j]--;div*=rev[cnt[j]]*fac[cnt[j]+1]%mo;div%=mo;
				ans+=tmp*div%mo;ans%=mo;
				div*=rev[cnt[j]+1]*fac[cnt[j]]%mo;cnt[j]++;div%=mo;
			}
	}	
	For(i,'a','z')	cnt[i]=0;
	For(i,1,len)	cnt[a[i]]++;
	For(pre,0,len)
	{
		ll tmp=fac[len-pre-1];
		ll div=1;
		if(pre!=0)	
		{
			if(cnt[a[pre]])	cnt[a[pre]]--;
			else	break;
		}
		For(j,'a','z')	div*=rev[cnt[j]],div%=mo;
		For(j,'a',a[pre+1]-1)
			if(cnt[j])
			{
				cnt[j]--;div*=rev[cnt[j]]*fac[cnt[j]+1]%mo;div%=mo;
				ans1+=tmp*div%mo;ans1%=mo;
				div*=rev[cnt[j]+1]*fac[cnt[j]]%mo;cnt[j]++;div%=mo;
			}
	}
	writeln(((ans-ans1-1)+2*mo)%mo);
}