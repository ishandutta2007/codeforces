#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	int px,py;
	scanf("%d%d%s",&px,&py,s+1);
	
	int n = strlen(s+1);
	vector<int> cnt(5);
	int x = 0, y = 0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == 'U') ++y, ++cnt[1];
		if(s[i] == 'D') --y, ++cnt[2];
		if(s[i] == 'L') --x, ++cnt[3];
		if(s[i] == 'R') ++x, ++cnt[4];
	}
	
	int dx = x - px, dy = y - py;
	
	bool ok = 1;
	if(dx < 0 && cnt[3] < -dx) ok = 0;
	if(dx > 0 && cnt[4] < dx) ok = 0;
	if(dy < 0 && cnt[2] < -dy) ok = 0;
	if(dy > 0 && cnt[1] < dy) ok = 0;
	
	if(ok) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}