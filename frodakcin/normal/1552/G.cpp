
#include <cstdio>
#include <vector>
#include <algorithm>

using ll = long long;

const int MN = 42;
const int MK = 12;

int N, K;
ll a[MK], fill[MN];

std::vector<ll> cur, nxt;

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<K;++i)
	{
		int x; scanf("%d", &x);
		for(int j=0, v;j<x;++j)
			scanf("%d", &v), a[i]|=1ll<<v-1;
	}

	if(N==1)
		return printf("ACCEPTED\n"), 0;
	if(K==0)
		return printf("REJECTED\n"), 0;

	{
		ll m=0;
		for(int i=0;i+1<K;++i)
			m |= a[i];
		if(m+1 != 1ll<<N)
		{
			if(a[K-1]+1==1ll<<N)
				printf("ACCEPTED\n");
			else
				printf("REJECTED\n");
			return 0;
		}
	}

	cur.push_back(0);
	ll m=0;
	for(int i=0;i<K;++i)
	{
		{
			ll v = a[i];
			for(int j=0;;++j)
			{
				fill[j] = v;
				if(v)
					v -= -v&v;
				else
					break;
			}
		}
		for(ll x:cur)
		{
			int min = __builtin_popcountll(a[i]&~x&m); // min # of zeroes
			int max = __builtin_popcountll(a[i])-__builtin_popcountll(a[i]&x); // max # of zeroes = # items minus min # of ones
			x &= ~a[i];
			for(int c=min;c <= max;++c)
				nxt.push_back(x|fill[c]);
		}
		m |= a[i];

		std::swap(cur, nxt);
		nxt.clear();
		std::sort(cur.begin(), cur.end());
		cur.resize(std::distance(cur.begin(), std::unique(cur.begin(), cur.end())));
	}

	bool ok=1;
	for(ll x:cur)
		if(x != 0 && __builtin_ctzll(x) + __builtin_popcountll(x) != N)
		{
			ok=0;
			break;
		}
	if(ok)
		printf("ACCEPTED\n");
	else
		printf("REJECTED\n");
	return 0;
}