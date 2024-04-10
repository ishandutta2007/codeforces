#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXD = 20 + 5;

void write(__int128 x)
{
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}

int c[MAXN][MAXD];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=d; ++j)
			scanf("%d",&c[i][j]);
	
	auto enco = [&] (int f[])
	{
		ll res = 0;
		for(int i=1; i<=d; ++i)
			res = res * 3 + f[i];
		return res;
	};
	
	map<ll,int> id;
	for(int i=1; i<=n; ++i)
		id[enco(c[i])] = i;
	
	static int cnt[MAXN];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
		{
			static int f[MAXD];
			for(int k=1; k<=d; ++k)
				f[k] = c[i][k] == c[j][k]? c[i][k]: 3 ^ c[i][k] ^ c[j][k];
			
			ll t = enco(f);
			if(id.count(t))
				++cnt[id[t]];
		}
	
	__int128 ans = 0;
	for(int i=1; i<=n; ++i)
		ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
	write(ans);
	return 0;
}