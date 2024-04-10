#include <cstdio>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>

const int MN = 2e2+10;
int N, a[MN*3], p[MN*2], c[MN*2], G;
bool u[MN*6], t[MN*2];
std::vector<int> d[MN*2], g[MN*2];
std::stack<int> s;
std::queue<int> q[2];

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N*3;++i)
	{
		scanf("%d", a+i);
		u[a[i]]=1;
	}
	for(int i=1;i<=N*2;++i)
		g[i].reserve(3);
	for(int i=1;i<=N*6;++i)
		if(s.empty() || t[s.top()] != u[i])
		{
			s.push(++G);
			t[G]=u[i];
			g[G].push_back(i);
		}
		else
		{
			g[s.top()].push_back(i);
			if(g[s.top()].size() == 3)
			{
				int n=s.top(); s.pop();
				int P=s.empty()?0:s.top();
				assert(!P || t[P]!=t[n]);
				d[P].push_back(n);
				p[n]=P;
			}
		}
	assert(s.empty());
	assert(G==N*2);
	for(int i=0;i<=G;++i)
	{
		c[i]=d[i].size();
		if(!c[i])
			q[t[i]].push(i);
	}
	int lst=-1, ctr=0;
	for(int x:d[0])
		if(!t[x])
			++ctr;
	for(int i=1;i<=N*2;++i)
	{
		assert(!q[i&1].empty());
		int n=q[i&1].front(); q[i&1].pop();
		if(!(i&1) && !p[n])
		{
			if(i < N*2 && ctr == 1)
			{
				q[0].push(n);
				--i;
				continue;
			}
			--ctr;
		}
		printf("%d %d %d\n", g[n][0], g[n][1], g[n][2]);
		if(!--c[p[n]])
			q[t[p[n]]].push(p[n]);
	}
	return 0;
}