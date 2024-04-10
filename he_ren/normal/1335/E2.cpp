#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXA = 2e2 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];
vector<int> pos[MAXA];
int sum[MAXA][MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int maxa=0;
	for(int i=1; i<=n; ++i) chk_max(maxa, a[i]);
	
	for(int i=1; i<=maxa; ++i) pos[i].clear();
	for(int i=1; i<=n; ++i) pos[a[i]].push_back(i);
	
	for(int i=1; i<=maxa; ++i)
		for(int j=1; j<=n; ++j)
		{
			sum[i][j] = sum[i][j-1];
			if(a[j]==i) ++sum[i][j];
		}
	
	int ans=0;
	for(int i=1; i<=maxa; ++i)
	{
		int tot = pos[i].size();
		chk_max(ans, tot);
		for(int j=1; (j<<1)<=tot; ++j)
		{
			int l = pos[i][j-1]+1;
			int r = pos[i][tot-j]-1;
			
			for(int k=1; k<=maxa; ++k)
			{
				chk_max(ans, (j<<1)+sum[k][r]-sum[k][l-1]);
			}
		}
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}