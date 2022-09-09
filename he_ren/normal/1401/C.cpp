#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int mn = a[1];
	for(int i=1; i<=n; ++i)
		mn = min(mn, a[i]);
	
	vector<int> b,pos;
	for(int i=1; i<=n; ++i)
		if(a[i] % mn == 0)
			b.push_back(a[i]),
			pos.push_back(i);
	
	sort(b.begin(), b.end());
	for(int i=0; i<(int)b.size(); ++i)
		a[pos[i]] = b[i];
	
	for(int i=1; i<n; ++i)
		if(a[i] > a[i+1])
		{
			printf("NO\n");
			return;
		}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}