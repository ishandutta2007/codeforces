#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	vector<int> cnt(30);
	for(int i=1; i<=n; ++i)
		++cnt[s[i] - 'A'];
	
	int mx = 0;
	for(int i=0; i<26; ++i)
		if(cnt[i] > cnt[mx]) mx = i;
	
	char c;
	if(mx == 'R' - 'A') c = 'P';
	if(mx == 'S' - 'A') c = 'R';
	if(mx == 'P' - 'A') c = 'S';
	
	for(int i=1; i<=n; ++i) putchar(c);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}