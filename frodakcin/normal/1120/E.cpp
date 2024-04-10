#include <iostream>
#include <cstdio>

#include <queue>
#include <bitset>

using namespace std;

int A;
const int MA = 1e3 + 10;
const int MC = 1e4 + 10;

const int MV = 2e6;
struct S
{
public:
	int c, b;
	S * p;
	int v;
	void setn(S& o, const int& x)
	{
		int w = c + A*x;
		o.c = w/10, o.b = b + A*(w%10) - x, o.p = this, o.v = x;
	}
	bool isd(void) const
	{
		return c == 0&&b == 0;
	}
	bool inb(void) const
	{
		return -A <= b&&b <= A&&c < MC;
	}
};
S s[MV];
int c;
using vb = bitset<MC>;
vb v[MC];

using qs = queue<int>;
qs q;

S * f;
void bfs(int k)
{
	q.push(0);
	for(int i, u, x;!q.empty();)
	{
		i = q.front(), q.pop();
		S& n = s[i];
		for(u = 0;u < 10;u++)
		{
			if(!u&&n.isd())
				continue;
			n.setn(s[c], u);
			if(s[c].inb())
			{
				if(s[c].isd())
				{
					f = &s[c];
					return;
				}
				if(v[s[c].b+A][s[c].c])
					continue;
				v[s[c].b+A][s[c].c] = 1;
				q.push(c++);
			}
		}
	}
}
void ans(S * n)
{
	bool L = 0;
	for(;n->p;n=n->p)
		if(L||n->v)
			printf("%d", n->v), L = 1;
}
			
int main(void)
{
	scanf("%d", &A);
	s[0] = {0, 0, nullptr, -1};
	c = 1;
	f = nullptr;
	bfs(0);
	if(f)
		ans(f), printf("\n");
	else
		printf("-1\n");
	return 0;
}