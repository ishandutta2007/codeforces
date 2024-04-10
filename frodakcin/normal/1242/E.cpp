#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define NDEBUG
#include <cassert>

const int MF = 1e5 + 100;
const int MN = 3e5 + 100;

using ll = long long;

int F, a[MF], m[MF], o[MF], p[MF];
std::vector<int> f[MF];
int C, Q = 1;
std::set<int> b[MN];

struct LLN
{
public:
	static int X;
	LLN * p, * n;
	int val;
};

int LLN::X = 0;
LLN pool[2*MN];
LLN * nn(int val, LLN * p = nullptr, LLN * n = nullptr)
{
	assert(LLN::X < 2*MN);
	pool[LLN::X].val = val, pool[LLN::X].p = p, pool[LLN::X].n = n;
	return pool+LLN::X++;
}
LLN * root = nullptr;

bool edge(int u, int v)
{
	assert(v != u);
	if(v < u) std::swap(u, v);
	return b[u].find(v) != b[u].end();
}
void pre(void)
{
	root = nn(Q), f[F-1].push_back(Q), ++Q;
	LLN * cur = root;
	for(int i = 0;i < a[F-1]-1;++i)
	{
		b[Q-1].insert(Q);
		cur->n = nn(Q);
		cur->n->p = cur;
		cur = cur->n;
		f[F-1].push_back(Q), ++Q;
	}
}
		

int main(void)
{
	scanf("%d", &F);
	for(int i = 0;i < F;++i)
		scanf("%d", a+i), m[i] = a[i], C += a[i];
	std::sort(a, a+F);
	for(int i = 0, t;i < F;++i)
		t = std::lower_bound(a, a+F, m[i]) - a, m[i] = t+o[t]++;
	for(int i = 0;i < F;++i)
		p[i+1] = p[i] + a[i];
	pre();
	int cur = a[F-1];
	for(int i = F-2, d;i >= 0;--i)
	{
		if(cur + a[i] - 2 - (p[i] - i*2) <= 4)
			d = 1;
		else if(cur - a[i] + 2 - (p[i] - i*2) >= 3)
			d = a[i]-1;
		else
			d = (cur + a[i] - 3 - (p[i] - i*2))/2;
		assert(0 < d && d < a[i]);
		LLN * x = root, * y = root;
		for(int j = 0;j < d;++j)
			y = y->n;
		if(d+1 == a[i] && edge(x->val, y->val))
			x = x->n, y = y->n;
		for(LLN * k = y;k != x;k = k->p)
			f[i].push_back(k->val);
		f[i].push_back(x->val);
		for(int j = 0;j < a[i]-d-1;++j)
		{
			x->n = nn(Q);
			f[i].push_back(Q);
			b[x->val].insert(Q), ++Q;
			x->n->p = x, x = x->n;
		}
		x->n = y, y->p = x;
		if(d+1 < a[i])
			b[y->val].insert(x->val);
		
		cur += a[i] - 2*d;
	}
	printf("%d\n", Q-1);
	for(int i = 0;i < F;++i)
	{
		for(int x : f[m[i]])
			printf("%d ", x);
		printf("\n");
	}
	return 0;
}