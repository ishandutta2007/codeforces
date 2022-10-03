#include<bits/stdc++.h>
using namespace std;
#define ll long long

int num[100010],n,c,d;
char ch[100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();c=rd();d=rd();
	for (int i=1;i<=n;i++)
	{
		num[i]=rd();
		scanf("%c",&ch[i]);
	}
	num[n+1]=rd();
	ch[n+1]='Q';
	int lst=num[n+1],now=0;
	ll ans=(ll)d*n;
	for (int i=n;i;i--)
	{
		if (ch[i]==ch[i+1]) now+=min(d,c*(lst-num[i+1]));
		else now+=c*(lst-num[i+1]),lst=num[i+1];
		ans=min(ans,(ll)d*(i-1)+now+c*(lst-num[i]));
	}
	printf("%lld\n",ans);
	return 0;
}