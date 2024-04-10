#include <cstdio>
#include <map>
#include <algorithm>
#include <cassert>
//#define NDEBUG

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MN = 6e5 + 100;
const ll BASE = 1e17;

int N, n;
int M;

ll ans, cans;
ll ans_big;
int a26;
int a30;
char C;
int curmin = 1<<30;
int c, w;

int s[MN];
int dne[MN][26];
int kmp[MN];

int segtree[1 << 21];
void set(int n, int l, int r, int q, int v)
{
	if(r-l>1)
	{
		int m = l + (r-l)/2;
		if(q < m) set(n<<1, l, m, q, v);
		else set(n<<1|1, m, r, q, v);
		segtree[n] = std::min(segtree[n<<1], segtree[n<<1|1]);
	}
	else
		segtree[n] = v;
}
int qry(int n, int l, int r, int ql, int qr)
{
	if(ql <= l&&r <= qr)
		return segtree[n];
	int m = l + (r-l)/2, f = 1<<30;
	if(ql < m) f = std::min(f, qry(n<<1, l, m, ql, qr));
	if(m < qr) f = std::min(f, qry(n<<1|1, m, r, ql, qr));
	return f;
}

std::map<int, int> qnt;
void remove(int v)
{
	std::map<int, int>::iterator it = qnt.find(v);
	assert(it != qnt.end());
	if(!--it->second)
		qnt.erase(it);
	cans -= v;
}
void finalize(int v)
{
	ll k = 0LL;
	int c = 0;
	std::map<int, int>::iterator it = qnt.end();
	for(;!qnt.empty();)
		if((--it)->first >= v)
		{
			k += tl(it->first)*it->second;
			c += it->second;
			it = qnt.erase(it);
		}
		else break;
	cans += tl(c)*v - k;
	qnt.insert({v, c});
}
void insert(int v)
{
	std::map<int, int>::iterator it = qnt.find(v);
	if(it == qnt.end()) qnt.insert({v, 1});
	else ++it->second;
	cans += v;
}

void query()
{
	scanf(" %c%d", &C, &w), c = C-97;
	c = static_cast<char>((c+a26)%26), w ^= a30;

	s[n] = c;
	if(w < curmin) curmin = w;
	if(n > 1)
		for(int i = dne[n-1][c];i;i = dne[i][c])
			remove(qry(1, 0, M, n-i, n));//, printf("\t%d->%d\n", n, i);
	if(n == 1) kmp[n] = 0;
	else
	{
		int v = kmp[n-1];
		for(;v;)
			if(s[v+1] != c)
				v = kmp[v];
			else break;
		if(s[v+1] == c) kmp[n] = ++v;
		else kmp[n] = v, assert(v == 0);

		for(int i = 0;i < 26;++i)
			dne[n][i] = v;
		if(v)
			dne[n][s[v+1]] = dne[v][s[v+1]];
	}
	set(1, 0, M, n, w);
	finalize(w);

	if(n > 1 && s[n] == s[1])
		insert(w);

	ans += cans;
	ans += curmin;

	a26 = ti((a26+cans+curmin)%26);
	a30 = ti((a30+cans+curmin)&((1<<30LL)-1));

	if(ans >= BASE)
		ans_big += ans/BASE, ans %= BASE;

	if(ans_big)
	{
		printf("%lld", ans_big);
		for(ll i = BASE/10;i > ans;i /= 10) printf("0");
		if(ans) printf("%lld", ans);
		printf("\n");
	}
	else
		printf("%lld\n", ans);
}

int main(void)
{
	for(int i = 0;i < 1<<21;++i)
		segtree[i] = 1 << 30;
	scanf("%d", &N);
	M = N + 10;
	for(n = 1;n <= N;++n)
		query();
	return 0;
}