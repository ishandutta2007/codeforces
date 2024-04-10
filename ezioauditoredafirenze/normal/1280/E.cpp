#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;
const LL OO = 0x3f3f3f3f3f3f3f3f;

const int maxn = 2000100;

char s[maxn + 5];

int N;

vector<int> chd[maxn + 5];
int ty[maxn + 5];
int id[maxn + 5];

LL f[maxn + 5];

LL ans[maxn + 5];

void calc(int x)
{
	if (ty[x] == 2)
	{
		f[x] = 1;
		return;
	}
	if (ty[x] == 0) f[x] = OO;
	else f[x] = 0;
	for (auto y : chd[x])
	{
		calc(y);
		if (ty[x] == 0) chkmin(f[x], f[y]);
		else f[x] += f[y];
	}
}

void dfs(int x, LL w)
{
	if (ty[x] == 2)
	{
		ans[id[x]] = w;
		return;
	}
	if (ty[x] == 0)
	{
		int Miny = -1;
		for (auto y : chd[x])
			if (!~Miny || f[y] < f[Miny]) Miny = y;
		dfs(Miny, w);
	}
	else
	{
		for (auto y : chd[x])
			dfs(y, w);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int r;
		scanf("%d", &r);
		char c;
		int n = 0;
		while (isprint(c = getchar())) if (c != ' ') s[n++] = c;
		N = 0;
		vector<int> stk;
		ty[N] = 0;
		chd[N].clear();
		stk.pb(N++);
		int m = 0;
		REP(i, 0, n)
		{
			if (s[i] == '(')
			{
				ty[N] = 0;
				chd[N].clear();
				chd[stk.back()].pb(N);
				stk.pb(N++);
			}
			else if (s[i] == '*')
			{
				ty[N] = 2;
				id[N] = m++;
				chd[N].clear();
				chd[stk.back()].pb(N);
				N++;
			}
			else if (s[i] == ')') stk.pop_back();
			else if (s[i] == 'S') ty[stk.back()] = 0;
			else if (s[i] == 'P') ty[stk.back()] = 1;
		}
		calc(0);
		REP(i, 0, m) ans[i] = 0;
		dfs(0, r * f[0]);
		printf("REVOLTING ");
		REP(i, 0, m) printf("%lld ", ans[i]);
		printf("\n");
	}
	return 0;
}