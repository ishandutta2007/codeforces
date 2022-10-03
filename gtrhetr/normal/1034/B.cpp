#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();m=rd();
	if (n==2&&m==2) { puts("0");return 0; }
	if (n==1||m==1)
	{
		if (m==1) swap(n,m);
		if (m%6<=3) { printf("%lld\n",m-(m%6));return 0; }
		if (m%6==4) { printf("%lld\n",m-2);return 0; }
		if (m%6==5) { printf("%lld\n",m-1);return 0; }
	}
	if ((n&1)&&(m&1)) { printf("%lld\n",n*m-1);return 0; }
	if (!(n&1)&&!(m&1)) { printf("%lld\n",n*m);return 0; }
	if (!(m&1)) swap(n,m);
	if (n>2) { printf("%lld\n",n*m);return 0; }
	if (m==3||m==7) { printf("%lld\n",n*m-2);return 0; }
	printf("%lld\n",n*m);
	return 0;
}