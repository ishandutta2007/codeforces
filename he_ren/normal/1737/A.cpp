#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 200 + 5;

char s[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	int cnt[30];
	memset(cnt, 0, sizeof(cnt));
	for(int i=1; i<=n; ++i)
		++cnt[s[i] - 'a'];
	
	for(int i=1; i<=d; ++i)
	{
		int res = 0;
		while(res < n/d && cnt[res])
			--cnt[res], ++res;
		putchar(res + 'a');
	}
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}