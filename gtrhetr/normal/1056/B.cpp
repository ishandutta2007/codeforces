#include<bits/stdc++.h>
using namespace std;
#define ll long long

int sum[1010];
int n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();m=rd();
	for (int i=0;i<m;i++) sum[i]=n/m;
	for (int i=1;i<=n%m;i++) sum[i]++;
	ll ans=0;
	for (int i=0;i<m;i++) for (int j=0;j<m;j++) if ((i*i+j*j)%m==0) ans+=(ll)sum[i]*sum[j];
	printf("%lld\n",ans);
	return 0;
}