#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

const int MV = 1e6 + 10;
const int MP = 8e4;

bool cp[MV];
int p[MP], P = 1;
int n[MV], l[MV], cnt[MV];
void gen()
{
	l[0] = l[1] = 0;
	p[0] = 1;
	for(int i = 2;i < MV;++i)
	{
		if(!cp[i])
			n[i] = 1, l[i] = P, p[P++] = i, cnt[i] = 1;
		for(int j = 1, k, J = (MV-1)/i;j < P && p[j] <= J;++j)
		{
			k = i*p[j];
			assert(!cp[k]);
			cp[k] = 1;
			n[k] = i, l[k] = j, cnt[k] = 1;
			if(l[i] == j)
			{
				cnt[k] = cnt[i]+1;
				n[k] = n[i];
				break;
			}
		}
	}
}
int conv(int x)
{
	int y = 1;
	for(;x>1;x = n[x])
		if(cnt[x]&1)
			y *= p[l[x]];
	return y;
}
void get(int x, int * a, int * b)
{
	*a = l[x];
	*b = l[n[x]];
}

const int MN = 1e5 + 100;
int N, a[MV];
std::vector<int> b[MN];
bool u[MV];
int ans;

int d[MP], pa[MP];
std::queue<int> q;
int main(void)
{
	gen();
	scanf("%d", &N);
	for(int i = 0;i < N;++i)
	{
		scanf("%d", a+i);
		int x = -1, y = -1;
		a[i] = conv(a[i]);
		if(a[i] == 1)
			ans = 1;
		else if(u[a[i]])
		{
			if(!ans) ans = 2;
		}
		else
		{
			u[a[i]] = 1;
			int u, v;
			get(a[i], &u, &v);
			b[u].push_back(v), b[v].push_back(u);
		}
	}
	if(ans)
		return printf("%d\n", ans), 0;
	ans = N+1;
	for(int i = 0;i < P;++i)
		std::sort(b[i].begin(), b[i].end(), std::greater<int>());
	for(int i = 0, j = P-1;i < P;++i)
	{
		for(;j >= 0 && p[i]*p[j] >= MV;--j);
		if(j < i) break;
		memset(d+i+1, -1, sizeof(d[0])*(j-i));
		q.push(i);
		d[i] = 0, p[i] = -1;
		for(int x;!q.empty();q.pop())
		{
			x = q.front();
			for(int y : b[x])
				if(y == pa[x])
					continue;
				else if(!~d[y])
					pa[y] = x, d[y] = d[x] + 1, q.push(y);
				else
					ans = std::min(ans, d[x]+d[y]+1);
		}
		for(int y : b[i])
		{
			assert(!b[y].empty() && b[y].back() == i);
			b[y].pop_back();
		}
	}
	printf("%d\n", ans > N ? -1 : ans);
	return 0;
}