#include <cstdio>
#include <deque>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MN = 3e3 + 100;

int N, M, A, B;
int h[MN][MN];
int h1[MN][MN];
int g[MN*MN];

void take_input(void)
{
	ll x, y, z;
	scanf("%lld%lld%lld%lld", g, &x, &y, &z);
	for(int i = 1;i < M*N;i++)
		g[i] = static_cast<int>((g[i-1] * x + y)%z);
	for(int i = 0;i < N;i++)
		for(int j = 0;j < M;j++)
			h[i][j] = g[i*M+j];
	//for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) printf("%d%c", h[i][j], " \n"[j==M-1]);
}

deque<int> q;
int main(void)
{
	scanf("%d%d%d%d", &N, &M, &A, &B);
	take_input();
	for(int i = 0;i < M;i++, q.clear())
		for(int j = N-1;j >= 0;j--)
		{
			if(!q.empty() && q.front() >= j+A)
				q.pop_front();
			for(;!q.empty() && h[q.back()][i] >= h[j][i];q.pop_back());
			q.push_back(j);
			h1[j][i] = h[q.front()][i];
		}
	//for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) printf("%d%c", h1[i][j], " \n"[j==M-1]);
	for(int i = 0;i < N;i++, q.clear())
		for(int j = M-1;j >= 0;j--)
		{
			if(!q.empty() && q.front() >= j+B)
				q.pop_front();
			for(;!q.empty() && h1[i][q.back()] >= h1[i][j];q.pop_back());
			q.push_back(j);
			h[i][j] = h1[i][q.front()];
		}
	//for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) printf("%d%c", h[i][j], " \n"[j==M-1]);
	ll ans = 0;
	for(int i = 0;i+A <= N;i++)
		for(int j = 0;j+B <= M;j++)
			ans += h[i][j];
	printf("%lld\n", ans);
	return 0;
}