#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define lowbit(x) ((x)&(-(x)))

set<pll> st,st2;
deque<ll> q;
set<ll> t,st1;

ll ans[100010];
ll num[100010],c[100010],n,p;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline void add(int x,int y) { for (;x<=n;x+=lowbit(x)) c[x]+=y; }

inline ll query(int x)
{
	int res=0;
	for (;x;x-=lowbit(x)) res+=c[x];
	return res;
}

int main()
{
	n=rd();p=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=n;i++) t.insert(num[i]);
	t.insert(0);
	for (int i=1;i<=n;i++) st.insert(pll(num[i],i));
	for (int i=1;i<=n;i++) add(i,1);
	int tt=0;
	ll lst=0;
	while (tt<n)
	{
		ll now=*t.begin();t.erase(now);
		while (!st2.empty()&&(st2.begin())->first<=now) add((st2.begin())->second,1),st2.erase(st2.begin());
		while (!st.empty()&&(st.begin())->first<=now)
		{
			pll hh=*st.begin();st.erase(hh);
			st1.insert(hh.second);
		}
		if (!st1.empty())
		{
			ll hh=*st1.begin();
			if (query(hh)==hh)
			{
				add(hh,-1);st1.erase(hh);
				q.push_back(hh);
			}
		}
		if (now>=lst&&!q.empty())
		{
			ll hh=q.front();q.pop_front();
			lst=now+p;lst=now+p;ans[hh]=lst;
			t.insert(lst);
			st2.insert(pll(lst,hh));tt++;
		}
	}
	for (int i=1;i<=n;i++) print(ans[i]);
	putchar('\n');
	return 0;
}