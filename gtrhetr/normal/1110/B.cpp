#include<bits/stdc++.h>
using namespace std;
#define ll long long

int num[100010],b[100010],n,m,k;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();m=rd();k=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	ll ans=0;
	if (k==n) { printf("%d\n",n);return 0; }
	for (int i=1;i<n;i++) b[i]=num[i+1]-num[i]-1;
	sort(b+1,b+n);
	reverse(b+1,b+n);
	ans=num[n]-num[1]+1;
	for (int i=1;i<k;i++) ans-=b[i];
	printf("%I64d\n",ans);
	return 0;
}