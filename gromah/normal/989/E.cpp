#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef double LD;
#define N 200 + 5
#define M 10000 + 5
#define K 100
#define LOGM 14
#define mp make_pair

int n, q, X[N], Y[N], Log[M];
LD Ans[N];
vector <vector <int>> Lines[N];
map <pair <int, int>, int> Map;

struct Rec
{
	int r, c;
	LD num[N][N];
	Rec () {r = c = 0; memset(num, 0, sizeof(num));}
	Rec operator * (const Rec &a)
	{
		Rec res;
		res.r = r, res.c = a.c;
		for (int i = 0; i < res.r; i ++)
			for (int k = 0; k < c; k ++)
			{
				LD t = num[i][k];
				for (int j = 0; j < res.c; j ++)
					res.num[i][j] += t * a.num[k][j];
			}
		return res;
	}
	void out()
	{
		puts("----------------------------------------");
		for (int i = 0; i < r; i ++)
			for (int j = 0; j < c; j ++)
				printf("%.3f%c", (double) num[i][j], j == c - 1 ? '\n' : ' ');
	}
}A[LOGM], T[K + 1], g;

struct Query
{
	int t, m, id;
	void init(int _id)
	{
		scanf("%d%d", &t, &m);
		t --, m --, id = _id;
	}
	bool operator < (const Query &a) const
	{
		return m < a.m;
	}
}Q[N];

void Normalize(int &x, int &y)
{
	int d = __gcd(x, y);
	x /= d, y /= d;
	if (x < 0 || (x == 0 && y < 0))
		x = -x, y = -y;
}

void Handle(int id)
{
	Map.clear();
	for (int i = 0; i < n; i ++)
		if (i != id)
		{
			int x = X[i] - X[id], y = Y[i] - Y[id];
			Normalize(x, y);
			if (Map.find(mp(x, y)) == Map.end())
			{
				Map.emplace(mp(mp(x, y), Lines[id].size()));
				Lines[id].push_back({id});
			}
			int d = Map.find(mp(x, y)) -> second;
			Lines[id][d].push_back(i);
		}
}

void Init()
{
	for (int i = 2; i < M; i ++)
		Log[i] = Log[i >> 1] + 1;
	A[0].r = A[0].c = g.r = g.c = n;
	for (int i = 0; i < n; i ++)
		for (const vector<int> &line : Lines[i])
			for (const int &d : line)
				A[0].num[i][d] += 1.0 / (Lines[i].size() * line.size());
	for (int i = 0; i < n; i ++)
		g.num[i][i] = 1.0;
	T[0] = g;
	for (int i = 1; i <= K; i ++)
		T[i] = T[i - 1] * A[0];
	for (int i = 1; i < LOGM; i ++)
		A[i] = A[i - 1] * A[i - 1];
}

inline LD Calc(const vector<int> &line, int ed)
{
	LD res = 0.0;
	for (const int &d : line)
		res += g.num[d][ed];
	res /= line.size();
	return res;
}

LD Calc(int ed)
{
	LD Max = 0.0;
	for (int i = 0; i < n; i ++)
		for (const vector<int> &line : Lines[i])
			Max = max(Max, Calc(line, ed));
	return Max;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf("%d%d", X + i, Y + i);
	for (int i = 0; i < n; i ++)
		Handle(i);
	Init();
	scanf("%d", &q);
	for (int i = 1; i <= q; i ++)
		Q[i].init(i);
	sort(Q + 1, Q + q + 1);
	for (int i = 1, cur = 0; i <= q; i ++)
	{
		int step = Q[i].m - cur;
		int cnt_1 = 0, cnt_2 = (step + K - 1) / K;
		for (int t = step; t; t -= (t & -t))
			cnt_1 ++;
		if (cnt_1 <= cnt_2)
		{
			for (int t = step; t; t -= (t & -t))
				g = g * A[Log[t & -t]];
		}
		else
		{
			for (int t = step; t; t -= min(t, K))
				g = g * T[min(t, K)];
		}
		Ans[Q[i].id] = Calc(Q[i].t);
		cur = Q[i].m;
	}
	for (int i = 1; i <= q; i ++)
		printf("%.7f\n", (double) Ans[i]);
	return 0;
}