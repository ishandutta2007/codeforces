#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define mp make_pair

int n, m, tot, Max, Trie[N][26];
LL ans;
char s[N];

struct Node
{
	int fix, pos, rev_pos;
	bool flag, used;
	int Add(char *p, int len, int op)
	{
		int u = 0;
		for (int i = 0; i < len; i ++)
		{
			int d = *(p + i * op) - 'a';
			if (!Trie[u][d])
				Trie[u][d] = ++ tot;
			u = Trie[u][d];
		}
		return u;
	}
	void init(int id)
	{
		scanf("%s%d", s + id * m, &fix);
		flag = 1;
		for (int i = 0; flag && i < m - i - 1; i ++)
			flag = s[id * m + i] == s[id * m + m - i - 1];
		pos = Add(s + id * m, m, 1);
		rev_pos = Add(s + (id + 1) * m - 1, m, -1);
	}
	bool operator < (const Node a) const
	{
		return fix > a.fix;
	}
}A[N];

struct cmp
{
	bool operator () (const int &a, const int &b)
	{
		return mp(A[a].fix, -a) < mp(A[b].fix, -b);
	}
};

priority_queue <int, vector <int>, cmp> Q[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		A[i].init(i);
	sort(A, A + n);
	for (int i = 0; i < n; i ++)
		Q[A[i].pos].push(i);
	for (int i = 0; i < n; i ++)
	{
		if (A[i].used || Q[A[i].rev_pos].empty()) continue ;
		if (!A[i].flag)
		{
			int j = Q[A[i].rev_pos].top();
			if (A[j].used || A[i].fix + A[j].fix <= 0) continue ;
			ans += A[i].fix + A[j].fix;
			A[i].used = A[j].used = 1;
			Q[A[i].pos].pop(), Q[A[j].pos].pop();
		}
		else
		{
			Q[A[i].pos].pop();
			if (Q[A[i].pos].empty())
			{
				Q[A[i].pos].push(i);
				continue ;
			}
			int j = Q[A[i].pos].top();
			if (A[j].used || A[i].fix + A[j].fix <= 0)
			{
				Q[A[i].pos].push(i);
				continue ;
			}
			ans += A[i].fix + A[j].fix;
			A[i].used = A[j].used = 1;
			Q[A[i].pos].pop();
		}
	}
	for (int i = 0; i < n; i ++)
	{
		if (!A[i].flag) continue ;
		if (A[i].used)
			Max = max(Max, -A[i].fix);
		else Max = max(Max, A[i].fix);
	}
	printf("%I64d\n", ans + Max);
	return 0;
}