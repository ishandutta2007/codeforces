#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k;
char s[500010],t[500010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();k=rd();
	scanf("%s%s",s+1,t+1);
	ll id=1;
	while (s[id]==t[id]&&id<=n) id++;
	if (id==n+1) { printf("%lld\n",n);return 0; }
	if (k==1) { printf("%lld\n",n);return 0; }
	ll ans=id-1;
	ll num1=1,num2=1,num3=0;
	ans+=min(k,num1+num2);
	for (int i=id+1;i<=n;i++)
	{
		num3*=2;
		if (s[i]=='a') num3+=num1;
		if (t[i]=='b') num3+=num2;
		num1=min(num1,k);num2=min(num2,k);num3=min(num3,k);
		ans+=min(k,num1+num2+num3);
	}
	printf("%lld\n",ans);
	return 0;
}