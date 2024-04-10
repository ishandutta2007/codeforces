#include<bits/stdc++.h>
using namespace std;
#define ll long long

int num[1010][1010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) num[i][j]=rd();
	ll now=(ll)num[1][2]*num[1][3]/num[2][3];
	printf("%lld ",(ll)sqrt(now));
	now=(ll)num[2][1]*num[2][3]/num[1][3];
	printf("%lld ",(ll)sqrt(now));
	for (int i=3;i<=n;i++) printf("%lld ",(ll)sqrt((ll)num[i][1]*num[i][2]/num[1][2]));
	return 0;
}