#include<bits/stdc++.h>
using namespace std;
#define ll long long

queue<ll> q;

ll num[300010],n;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (ll i=1;i<=n;i++) num[i]=rd();
	ll ans=0;
	for (ll i=1;i<=n;i++) ans+=num[i];
	ll tt=0;
	for (ll i=n;i;i--)
	{
		if (num[i]!=1) { q.push(i);continue; }
		bool flag=false;
		while (!q.empty())
		{
			ll x=q.front();
			if (num[x]<2) { q.pop();continue; }
			if (num[x]==3) { q.pop();continue; }
			flag=true;num[x]-=2;break;
		}
		if (!flag) tt++;
	}
	printf("%lld\n",(ans-tt)/3);
	return 0;
}