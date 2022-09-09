#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN], b[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d%*d%*d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	static int p[MAXN], mn[MAXM];
	memset(mn,0x3f,sizeof(mn));
	
	for(int i=1,j=1; i<=n; ++i)
	{
		while(j<m && abs(b[j+1] - a[i]) <= abs(b[j] - a[i])) ++j;
		
		if(j>1 && abs(b[j-1] - a[i]) == abs(b[j] - a[i]) && (mn[j-1] == inf || mn[j-1] == abs(b[j-1] - a[i])))
			--j;
		p[i] = j;
		mn[j] = min(mn[j], abs(b[j] - a[i]));
	}
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		if(mn[p[i]] < abs(b[p[i]] - a[i]))
			++ans;
	printf("%d",ans);
	return 0;
}