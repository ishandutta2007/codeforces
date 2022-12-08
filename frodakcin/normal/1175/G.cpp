#include <iostream>
#include <cstdio>

#include <deque>

using namespace std;

template<class T> bool mn(T& a, const T& b) {return b<a?a=b,1:0;}
template<class T> bool mx(T& a, const T& b) {return b>a?a=b,1:0;}
template<class T> T mxv(T& a, const T& b) {return b>a?a=b:a;}

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MN = 2e4 + 100;
const int INF = 4e8 + 1000000;

int divf(int n, int d)
{
	if(d < 0) n *= -1, d *= -1;
	if(n<0) return -((-n+d-1)/d);
	else return n/d;
}

bool Q;
struct Line
{
public:
	int m, b;
	mutable int r;
	Line(int m, int b) : m(m), b(b) {r = -1;}
	Line(int r) : r(r) {m = -1, b = -1;}
	int operator * (const Line& o) const
	{
		if(m == o.m) return o.b < b ? -INF : INF;
		return divf(o.b-b, m-o.m);
	}
	int operator [] (const int& x ) const
	{
		return m * x + b;
	}
};
struct CHT : public deque<Line>
{
public:
	void insF(Line l)
	{
		if(!empty() && l.m == front().m && l.b >= front().b) return; 
		while(!empty() && (l.r = l*front()) >= front().r) pop_front();
		if(empty()) l.r = INF;
		push_front(l);
	}
	void insB(Line l)
	{
		if(!empty() && l.m == back().m && l.b >= back().b) return;
		while(!empty() && (l.r = back()*l) <= back().r) pop_back();
		if(empty()) l.r = -INF;
		push_back(l);
	}
	int qryF(int v)
	{
		for(;v > front().r; pop_front());
		return front()[v];
	}
	int qryB(int v)
	{
		for(;v <= back().r; pop_back());
		return back()[v];
	}
};
CHT cht;
void tcht(void)
{
	int T;
	scanf("%d", &T);
	for(int t, a, b;;)
	{
		scanf("%d", &t); if(!~t) return;
		if(t) {scanf("%d%d", &a, &b); if(T) cht.insF({a,b}); else cht.insB({a,b});}
		else {scanf("%d", &a); printf("%d\n", T ? cht.qryF(a) : cht.qryB(a));}
	}
}
int N, K;
int a[MN];
int dp[2][MN];
int v[MN];

void solve(int l, int r)
{
	int * f = dp[0], * t = dp[1];
	if(r-l == 1) return;
	int m = l + (r-l>>1);
	for(int i = m;i < r;i++)
		v[i] = i==m?a[i]:max(v[i-1], a[i]);
	for(int i = m-1;i >= l;i--)
		v[i] = i==m-1?a[i]:max(v[i+1], a[i]);
	
	cht.insF({0, f[m-1]});
	for(int i = m, j = m-2;i < r;i++)
	{
		for(;j >= l&&v[j+1] <= v[i];j--)
			cht.insF({m-j-1, f[j]});
		mn(t[i], cht.qryF(v[i])+v[i]*(i-m+1));
	}
	cht.clear();

	for(int i = r-1, j = l;i >= m;i--)
	{
		for(;j < m&&v[j]>=v[i];j++)
			cht.insB({v[j], f[j-1]+v[j]*(m-j)});
		if(!cht.empty())
			mn(t[i], cht.qryB(i-m+1));
	}
	cht.clear();

	solve(l, m);
	solve(m, r);
}
int main(void)
{
	scanf("%d%d", &N, &K);
	dp[1][0] = 0;
	for(int i = 1, m = 0;i <= N;i++)
		scanf("%d", a + i), dp[1][i]=i*mxv(m, a[i]);
	for(int i = 1;i < K;i++)
	{
		for(int j = 0;j <= N;j++)
			dp[0][j] = dp[1][j];
		solve(1, N+1);
	}
	printf("%d\n", dp[1][N]);
	return 0;
}