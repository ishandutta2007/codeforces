#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;

int a[MAXN][MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) scanf("%d",&a[i][j]);
	
	ll ans = 0;
	for(int i=1; i <= (n+1)/2; ++i)
		for(int j=1; j <= (m+1)/2; ++j)
		{
			vector<pii> vec;
			vec.push_back(make_pair(i,j));
			vec.push_back(make_pair(n-i+1,j));
			vec.push_back(make_pair(i,m-j+1));
			vec.push_back(make_pair(n-i+1,m-j+1));
			
			sort(vec.begin(), vec.end());
			
			vector<int> val;
			for(int k=0; k<(int)vec.size(); ++k)
				if(!k || vec[k] != vec[k-1])
					val.push_back(a[vec[k].first][vec[k].second]);
			
			ll res = 0x3f3f3f3f3f3f3f3f;
			for(int k=0; k<(int)val.size(); ++k)
			{
				ll tmp = 0;
				for(int l=0; l<(int)val.size(); ++l)
					tmp += val[l] < val[k]? val[k] - val[l]: val[l] - val[k];
				res = min(res, tmp);
			}
			ans += res;
		}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}