#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int n,m;
vector<int> a[MAXN];

inline int get_res(void)
{
	static int pos[MAXN];
	memset(pos, 0, (n+1)<<2);
	for(int res=0;; ++res)
	{
		static int rig[MAXN];
		memset(rig, 0x3f, (n+1)<<2);
		for(int i=n-1; i>=0; --i)
		{
			if(pos[i] < (int)a[i].size()) rig[i] = a[i][pos[i]];
			rig[i] = min(rig[i], rig[i+1] + 1);
		}
		if(rig[0] == inf) return res;
		
		int cur = rig[0];
		for(int i=0; i<n; ++i)
		{
			if(pos[i] < (int)a[i].size() && cur == a[i][pos[i]]) ++pos[i];
			if(cur+1 <= rig[i+1]) ++cur;
			else --cur;
		}
	}
}

string s[MAXN];

void solve(void)
{
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; ++i) cin >> s[i];
	
	int ans = 0;
	for(int k=0; k<=1; ++k)
	{
		for(int i=0; i<n; ++i)
		{
			a[i].clear();
			for(int j=(i&1)^k; j<m; j+=2)
				if(s[i][j] == '1')
					a[i].push_back(j);
		}
		ans += get_res();
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