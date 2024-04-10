#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	int cnt[3] = {0,0,0};
	for(int i=1; i<=n; ++i) ++cnt[s[i] - 'A'];
	int pos = max_element(cnt,cnt+3) - cnt;
	
	bool is[3] = {0,0,0};
	is[pos] = 1;
	for(int T=1; T<=2; ++T)
	{
		int cur = 0;
		bool ok = 1;
		for(int i=1; i<=n; ++i)
		{
			if(is[s[i] - 'A']) ++cur;
			else if(cur) --cur;
			else{ ok = 0; break;}
		}
		if(ok && !cur)
		{
			printf("YES\n");
			return;
		}
		is[0] ^= 1; is[1] ^= 1; is[2] ^= 1;
	}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}