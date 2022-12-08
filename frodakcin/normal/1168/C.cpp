#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

template<class T> bool mn(T& a, const T& b) {return b<a?a=b,1:0;}
const int MN = 3e5 + 100;
const int MB = 20;

int N, Q;
int dp[MN][MB];
int nex[MN][MB];
int u[MN];
int a[MN];

struct QR
{
	int id;
	int wh;
};
vector<QR> queries[MN];
vector<int> I, J;
#define pb push_back
bool ans[MN];
int main(void)
{
	scanf("%d%d", &N, &Q);
	for(int i = 0;i < N;i++)
		scanf("%d", a + i), u[i]=-1;
	for(int i = 0, x, y;i < Q;i++)
		scanf("%d%d", &x, &y), queries[--x].pb({i, --y});
	for(int i = 0;i <= N;i++)
		for(int j = 0;j < MB;j++)
			nex[i][j] = N, dp[i][j] = N;
	for(int i = N-1;i >= 0;i--)
	{
		I.clear(), J.clear();
		for(int j = 0;j < MB;j++)
			if(a[i]&1<<j)
				I.pb(j), dp[i][j] = i;
			else
				J.pb(j);
		for(int x : I)
			if(nex[i][x] != N&&u[nex[i][x]] != i)
			{
				u[nex[i][x]] = i;
				for(int y : J)
					mn(dp[i][y], dp[nex[i][x]][y]);
			}
		for(QR& x : queries[i])
			for(int j = 0, k = a[x.wh];j < MB;j++)
				if(k&1<<j&&dp[i][j] <= x.wh)
					{
						ans[x.id] = 1;
						break;
					}
		if(i)
			for(int j = 0;j < MB;j++)
				if(1&(a[i]>>j))
					nex[i-1][j] = i;
				else
					nex[i-1][j] = nex[i][j];
	}
	for(int i = 0;i < Q;i++)
		if(ans[i])
			printf("Shi\n");
		else
			printf("Fou\n");
	return 0;
}