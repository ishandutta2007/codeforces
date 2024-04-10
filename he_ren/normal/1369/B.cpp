#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int l=1;
	while(l<=n && s[l]=='0') ++l;
	
	int r=n;
	while(r>=1 && s[r]=='1') --r;
	
	for(int i=1; i<l; ++i) putchar('0');
	if(l <= r) putchar('0');
	for(int i=r+1; i<=n; ++i) putchar('1');
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}