#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int n;
int a[MAXN];

inline bool chk(int x)
{
	vector<int> b;
	for(int i=1; i<=n; ++i)
	{
		if(a[i] != x) b.push_back(a[i]);
	}
	
	int m = (int)b.size();
	for(int i=0; i<m; ++i)
		if(b[i] != b[m-i-1]) return 0;
	return 1;
}

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		if(a[i] != a[n-i+1])
		{
			if(chk(a[i]) || chk(a[n-i+1]))
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
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