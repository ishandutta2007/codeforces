#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
int T,n,cnt;
int a[20];
LL f[20][2550][50],bin[20],l,r;
bool vst[20][2550][30];
int fp[2550],p[50];
int gcd(int a,int b)
{	return b==0?a:gcd(b,a%b);
}
LL DP(int x,LL Left,int lcm,int flag)//  
{	if(x==0)return (Left%p[lcm]==0);
	if(!flag&&vst[x][Left][lcm])return f[x][Left][lcm];
	int k=flag?a[x]:9;
	LL tmp=0;
	for(LL i=0;i<=k;i++)
		tmp+=DP(x-1,(Left+i*bin[x-1])%2520,(i==0?lcm:fp[p[lcm]*i/gcd(p[lcm],i)]),flag&&i==k); 
	if(!flag)
	{	vst[x][Left][lcm]=1;
		f[x][Left][lcm]=tmp;
	}
	return tmp;
}
LL Calc(LL x)
{	a[0]=0;
	while(x)
	{	a[++a[0]]=x%10;
		x=x/10;
	}
	return DP(a[0],0LL,1,1);
}
int main()
{	scanf("%lld",&l);
	for(int i=1;i<=2520;i++)if(2520%i==0){fp[i]=++cnt; p[cnt]=i;}
	bin[0]=1;for(int i=1;i<=20;i++)bin[i]=bin[i-1]*10;
	while(~scanf("%lld%lld",&l,&r))
		printf("%lld\n",Calc(r)-Calc(l-1));
	return 0;
}