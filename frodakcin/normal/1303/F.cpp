#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
 
const int MN = 3e2 + 10;
const int MM = MN*MN;
const int MQ = 2e6 + 100;
int N, M, Q;
int p[MQ];
int a[MM];
 
struct UPD
{
public:
	int x, t;
};
std::stack<int> du;
std::vector<UPD> col[MQ];
int dp[MM], dr[MM];
bool din[MM];
int df(int n) {return ~dp[n] ? dp[n] = df(dp[n]) : n;}
bool dm(int a, int b)
{
	if(!din[a] || !din[b]) return 0;
	//printf("TRY TO MERGE: %d %d\n", a, b);
	a = df(a), b = df(b);
	if(a == b) return 0;
	//printf("\tSUCCESS\n");
	if(dr[a] < dr[b]) std::swap(a, b);
	dr[a] += dr[a]==dr[b], dr[b] = -1;
	dp[b] = a;
	return 1;
}
void dres()
{
	for(int x;!du.empty();du.pop())
	{
		x = du.top();
		dp[x] = -1, dr[x] = 0, din[x] = 0;
	}
}
int main(void)
{
	scanf("%d%d%d", &N, &M, &Q);
	memset(dp, -1, sizeof(dp[0])*(N*M));
	int pc = -1;
	for(int i = 0;i < Q;++i)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		if(c != pc)
			dres(), pc = c;
 
		int t = --x*M+--y;
		if(a[t] == c) continue;
		du.push(t);
		din[t] = 1;
		col[a[t]].push_back({t, i});
		a[t] = c;
 
		++p[i];
		if(x && dm(t-M, t)) --p[i];
		if(y && dm(t-1, t)) --p[i];
		if(x+1<N && dm(t+M, t)) --p[i];
		if(y+1<M && dm(t+1, t)) --p[i];
	}
	dres();
	for(int i = 0;i < N*M;++i)
		col[a[i]].push_back({i, Q});
	for(int i = 0, x, y;i < MQ;++i)
	{
		for(int j = col[i].size()-1;j >= 0;--j)
		{
			UPD v = col[i][j];
			int x = v.x/M, y = v.x-x*M;
 
			du.push(v.x);
			din[v.x] = 1;
 
			--p[v.t];
			if(x && dm(v.x-M, v.x)) ++p[v.t];
			if(y && dm(v.x-1, v.x)) ++p[v.t];
			if(x+1<N && dm(v.x+M, v.x)) ++p[v.t];
			if(y+1<M && dm(v.x+1, v.x)) ++p[v.t];
		}
		dres();
	}
	for(int i = 0, c = 1;i < Q;++i)
		printf("%d\n", c += p[i]);
	return 0;
}