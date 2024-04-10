#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ldb;
const int MAXN = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ldb eps = 1e-9;

struct Line
{
	ll k;
	ldb b, x;
	Line(void){}
	Line(ll k,ldb b): k(k), b(b), x(linf) {};
	inline ldb at(ldb q) const { return k * q + b;}
};

inline ldb inter(const Line &p,const Line &q){ return (p.b - q.b) / (q.k - p.k);}

int a[MAXN];
ll suma[MAXN];
ldb sumr[MAXN], sumq[MAXN], dp[2][MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		suma[i] = suma[i-1] + a[i];
		sumr[i] = sumr[i-1] + (ldb)1 / a[i];
		sumq[i] = sumq[i-1] + (ldb)suma[i] / a[i];
	}
	
	for(int i=0; i<=n; ++i) dp[0][i] = linf;
	dp[0][0] = 0;
	for(int k=1; k<=d; ++k)
	{
		int now = k&1, lst = !now;
		for(int i=0; i<=n; ++i) dp[now][i] = linf;
		
		deque<Line> lines;
		for(int i=k; i<=n; ++i)
		{
			if(dp[lst][i-1] < linf - eps)
			{
				Line p(-suma[i-1], -sumq[i-1] + sumr[i-1] * suma[i-1] + dp[lst][i-1]);
				
				bool flag = 1;
				if(lines.size() && lines.back().k == p.k)
				{
					if(lines.back().b > p.k) lines.pop_back();
					else flag = 0;
				}
				if(flag)
				{
					while((int)lines.size() >= 2 && inter(*(lines.end()-2), p) <= (lines.end()-2) -> x + eps)
						lines.pop_back();
					
					if(lines.size()) lines.back().x = inter(lines.back(), p);
					lines.push_back(p);
				}
			}
			
			while(lines.front().x < sumr[i]) lines.pop_front();
			
			dp[now][i] = lines.front().at(sumr[i]) + sumq[i];
		}
	}
	
	printf("%.20lf",(double)dp[d&1][n]);
	return 0;
}