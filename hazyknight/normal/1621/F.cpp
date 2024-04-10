#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int T,n,a,b,c;

char s[MAXN];

ll work(bool side,int L,int R,vector<int> v,int one)
{
	int seg = v.size() + 1,store = 0;
	ll res = 0,MAX = 0;
	while (v.size() && v.back() == 1)
		v.pop_back(),store++;
	while (1)
	{
		if (side)
		{
			if (seg < one)
			{
				one--;
				res += b;
			}
			else
				break;
		}
		else
		{
			if (seg == one)
			{
				if (!store)
				{
					if (v.size() || L >= 2 || R >= 2)
						res += a;
					else
						break;
				}
				else
				{
					if (v.size() || L >= 2 || R >= 2)
						MAX = max(MAX,res + a);
					store--;
					seg--;
					res -= c;
				}
			}
			else
			{
				if (v.size())
				{
					res += a;
					v.back()--;
				}
				else
				{
					if (L >= 2)
					{
						L--;
						res += a;
					}
					else if (R >= 2)
					{
						R--;
						res += a;
					}
					else if (store)
					{
						seg--;
						store--;
						res -= c;
					}
					else if (L)
					{
						L--;
						res -= c;
					}
					else if (R)
					{
						R--;
						res -= c;
					}
					else
						break;
				}
			}
			while (v.size() && v.back() == 1)
				v.pop_back(),store++;
		}
		side ^= 1;
		MAX = max(MAX,res);
	}
	return MAX;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d%s",&n,&a,&b,&c,s + 1);
		int L = 0;
		for (int i = 1;i <= n;i++)
		{
			if (s[i] == '1')
				break;
			L++;
		}
		if (L == n)
		{
			printf("%d\n",n == 1 ? 0 : a);
			continue;
		}
		int R = 0,one = 0;
		for (int i = n;i >= 1;i--)
		{
			if (s[i] == '1')
				break;
			R++;
		}
		char *t = s + L;
		n -= R + L;
		int cnt = 0;
		vector<int> v;
		for (int i = 1;i <= n;i++)
		{
			if (t[i] == '0')
				cnt++;
			else
			{
				one++;
				if (cnt)
				{
					v.push_back(cnt);
					cnt = 0;
				}
			}
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		printf("%lld\n",max(work(0,L,R,v,one),work(1,L,R,v,one)));
	}
	return 0;
}