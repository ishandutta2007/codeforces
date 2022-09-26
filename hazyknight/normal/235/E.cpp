#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <map>

#define ll long long

using namespace std;

int a,b,c,n;
int prime[2005];

bool mark[2005];

map<pair<int,int>,ll> f[2005][2005];

ll dfs(int a,int b,int c,int n)
{
	if (!n)
		return 1;
	int p = prime[n];
	ll ret = 0;
	pair<int,int> now(c,n);
	if (f[a][b].count(now))
		return f[a][b][now];
	for (int i = 0,x = 1;x <= a;i++,x *= p)
		for (int j = 0,y = 1;y <= b;j++,y *= p)
			for (int k = 0,z = 1;z <= c;k++,z *= p)
			{
				int tmp[3] = {a / x,b / y,c / z};
				sort(tmp,tmp + 3);
				ret += dfs(tmp[0],tmp[1],tmp[2],n - 1) * (i + j + k + 1);
			}
	return f[a][b][now] = ret;
}

int main()
{
	cin >> a >> b >> c;
	if (a > b)swap(a,b);
	if (a > c)swap(a,c);
	if (b > c)swap(b,c);
	memset(mark,1,sizeof(mark));
	for (int i = 2;i <= a || i <= b || i <= c;i++)
		if (mark[i])
		{
			prime[++n] = i;
			for (int j = i * i;j <= 2000;j += i)
				mark[j] = 0;
		}
	cout << dfs(a,b,c,n) % (1ll << 30) << endl;
	return 0;
}