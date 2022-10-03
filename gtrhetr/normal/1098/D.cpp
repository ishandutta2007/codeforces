#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<int,int> mp;
priority_queue<int,vector<int>,greater<int> > q[40];

ll sum[40];
int n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

int main()
{
	n=rd();
	int tt=0;
	while (n--)
	{
		char ch=getchar();
		for (;ch!='+'&&ch!='-';ch=getchar());
		int x=rd();
		if (ch=='-')
		{
			int hh=0,now=x;
			while (now) now>>=1,hh++;
			mp[x]--;sum[hh]-=x;tt--;
		}
		else
		{
			int hh=0,now=x;
			while (now) now>>=1,hh++;
			mp[x]++;q[hh].push(x);
			sum[hh]+=x;tt++;
		}
		if (!tt) { print(0);continue; }
		ll s=0;
		int ans=0;
		for (int i=1;i<=31;i++)
		{
			while (!q[i].empty()&&mp[q[i].top()]==0) q[i].pop();
			if (q[i].empty()) continue;
			if (s&&q[i].top()>s*2) ans++;
			s+=sum[i];
		}
		print(tt-1-ans);
	}
	return 0;
}