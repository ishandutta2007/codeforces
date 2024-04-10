#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>

struct edge
{
	public:
		int a,b,c;
};
std::vector<edge> f;

struct dat
{
	public:
		int l,r;
};
std::stack<dat> todo;

void adde(int a, int b, int c)
{
	f.push_back({a,b,c});
}

int L, R, D;

int main()
{
	scanf("%d%d", &L, &R);
	D = R-L+1;
	for(int i=31;i>=12;--i) // [12, 31] are "the machine"
	{
		int v=31-i;
		for(int j=i+1;j<=32;++j)
			adde(i, j, 1<<v);
	}

	bool v[20];
	memset(v, 0, sizeof v);
	int msb=31-__builtin_clz(D);
	D^=1<<msb;
	for(int x=D,i=0;x;x/=2, ++i)
		v[i]=x&1;

	for(int i=0,j;i<20;)
	{
		if(!v[i])
		{
			++i;
			continue;
		}
		for(j=i+1;j<20 && v[j];++j);
		todo.push({i,j});
		i=j;
	}

	for(int i=0;i<=msb;++i) // set source
		adde(1, 32-i, L);

	int cur=1<<msb; // [0, cur] done .. go on to (cur, D]
	for(int i=2;i<=11;++i) // [2, 11] are the "input"
	{
		if(todo.empty()) break;
		dat t = todo.top(); todo.pop();
		//L-1 + cur + ( 0 , 2^t.r-2^t.l ]
		//L + cur-2^t.l + [2^t.l, 2^t.r)

		adde(1, i, L); // L +
		int w = cur-(1<<t.l);
		//printf("%d\n", w);
		for(int j=t.l;j<t.r;++j)
			adde(i, (32-j-1), w); // edge weight must be positive.
		cur += (1<<t.r)-(1<<t.l);
	}
	assert(todo.empty());

	printf("YES\n");
	printf("32 %u\n", f.size());
	for(auto x:f) printf("%d %d %d\n", x.a, x.b, x.c);
	return 0;
}