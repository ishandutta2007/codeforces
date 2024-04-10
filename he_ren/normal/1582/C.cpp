#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int ans = inf;
	for(int k=0; k<26; ++k)
	{
		vector<int> pos;
		for(int i=1; i<=n; ++i)
			if(s[i] - 'a' != k) pos.push_back(i);
		if(pos.size() == 0)
		{
			printf("0\n");
			return;
		}
		
		int l = ((int)pos.size() + 1) / 2, r = (int)pos.size() / 2 + 1;
		--l; --r;
		
		bool ok = 1;
		int cur = 0;
		for(; l>=0; --l, ++r)
		{
			if(s[pos[l]] != s[pos[r]])
			{
				ok = 0;
				break;
			}
			
			int x = l? pos[l] - pos[l-1] - 1: pos[l] - 1;
			int y = r+1<(int)pos.size()? pos[r+1] - pos[r] - 1: n - pos[r];
			cur += max(x,y) - min(x,y);
		}
		
		if(ok) ans = min(ans, cur);
	}
	
	if(ans == inf) printf("-1\n");
	else printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}