#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

inline int dist(pii p,pii q){ return abs(p.first - q.first) + abs(p.second - q.second);}

pii p[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].first,&p[i].second);
	
	for(int i=1; i<=n; ++i)
	{
		bool flag = 1;
		for(int j=1; j<=n; ++j)
			if(dist(p[i], p[j]) > d){ flag = 0; break;}
		if(flag){ printf("1\n"); return;}
	}
	printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}