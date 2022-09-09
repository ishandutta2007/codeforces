#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	putchar('9');
	--n; int cur = 8;
	while(n--) putchar(cur + '0'), cur = (cur + 1) % 10;
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}