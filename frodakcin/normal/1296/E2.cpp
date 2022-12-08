#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>

const int MN = 2e5 + 10;
const int MC = 26;
int N, K;
char s[MN];
int ans;
struct pos
{
public:
	char c;
	int i;
	bool operator < (pos o) const {return c < o.c || !(o.c < c) && i < o.i;}
};
pos ord[MN];
int p[MN];

struct col
{
public:
	int c, t;
	bool operator < (col o) const {return t < o.t/* || !(o.t < t) && c < o.c*/;} // all t should be different
};
std::set<col> cur;
int res[MN];

int main(void)
{
	scanf("%d", &N);
	scanf(" %s", s);
	for(int i = 0;i < N;++i)
		ord[i] = {s[i], i};
	std::sort(ord, ord+N);
	for(int i = 0;i < N;++i)
		p[ord[i].i] = i;
	
	ans = 1;
	cur.insert({1, -1});
	for(int i = 0;i < N;++i)
	{
		if(p[i] < cur.begin()->t)
			res[i] = ++ans, cur.insert({ans, p[i]});
		else
		{
			std::set<col>::iterator it = std::prev(cur.upper_bound({-1, p[i]}));
			int c = it->c;
			cur.erase(it);
			cur.insert({c, p[i]});
			res[i] = c;
		}
	}

	printf("%d\n", ans);
	for(int i = 0;i < N;++i)
		printf("%d%c", res[i], " \n"[i+1==N]);
	return 0;
}