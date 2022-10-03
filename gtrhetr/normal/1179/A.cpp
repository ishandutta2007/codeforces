#include<bits/stdc++.h>
using namespace std;
#define inf 2123333333
#define ll long long
#define pii pair<int,int>

deque<int> q;

pii h[300010];

int num[300010],b[300010],n,m;

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
	for (int i=1;i<=n;i++) num[i]=rd();
	int mx=0;
	for (int i=1;i<=n;i++) mx=max(mx,num[i]);
	for (int i=1;i<=n;i++) q.push_back(num[i]);
	int now=0;
	while (q.front()!=mx)
	{
		now++;
		h[now].first=q.front();q.pop_front();
		h[now].second=q.front();q.pop_front();
		int h1=max(h[now].first,h[now].second);
		int h2=min(h[now].first,h[now].second);
		q.push_front(h1);q.push_back(h2);
	}
	int tt=0;
	while (!q.empty()) b[++tt]=q.front(),q.pop_front();
	while (m--)
	{
		ll x=rd();
		if (x<=now) printf("%d %d\n",h[x].first,h[x].second);
		else
		{
			ll hh=(x-now)%(n-1);
			if (!hh) hh=n-1;hh++;
			printf("%d %d\n",b[1],b[hh]);
		}
	}
	return 0;
}