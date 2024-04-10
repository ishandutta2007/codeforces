#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int n;
int a[MAXN];

inline int mex(void)
{
	static bool t[MAXN];
	memset(t,0,n+1);
	for(int i=1; i<=n; ++i) t[a[i]] = 1;
	for(int i=0; i<=n; ++i)
		if(!t[i]) return i;
	return n + 1;
}

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	vector<int> ans;
	while(1)
	{
		if(mex() == 0)
		{
			bool ok = 0;
			for(int i=1; i<=n; ++i)
				if(a[i] != i)
				{
					a[i] = 0;
					ans.push_back(i);
					ok = 1;
					break;
				}
			if(!ok) break;
		}
		
		int cur = mex();
		a[cur] = cur;
		ans.push_back(cur);
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}