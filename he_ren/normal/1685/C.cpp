#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];
int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	n *= 2;
	
	auto chk = [&] (void) -> bool
	{
		int cnt = 0;
		for(int i=1; i<=n; ++i)
		{
			cnt += s[i] == '('? 1: -1;
			if(cnt < 0) return 0;
		}
		return 1;
	};
	
	for(int i=1; i<=n; ++i) a[i] = a[i-1] + (s[i] == '('? 1: -1);
	if(*min_element(a+1,a+n+1) >= 0)
	{
		printf("0\n");
		return;
	}
	
	int l = 0, r = n;
	while(a[l] >= 0) ++l;
	while(a[r] >= 0) --r;
	l = max_element(a+0, a+l) - a;
	r = max_element(a+r+1, a+n+1) - a;
	
	++l;
	reverse(s+l, s+r+1);
	if(chk())
	{
		printf("1\n");
		printf("%d %d\n",l,r);
		return;
	}
	
	int mx = max_element(a,a+n+1) - a;
	printf("2\n");
	printf("%d %d\n",1,mx);
	printf("%d %d\n",mx+1,n);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}