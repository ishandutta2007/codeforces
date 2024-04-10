#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> v[1000010];

int b[200010],n;

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
	for (int i=1;i<=n;i++) b[i]=rd();
	for (int i=1;i<=n;i++) v[b[i]-i+n].push_back(i);
	ll ans=0;
	for (int i=0;i<=1000000;i++)
	{
		ll res=0;
		for (int t:v[i]) res+=b[t];
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}