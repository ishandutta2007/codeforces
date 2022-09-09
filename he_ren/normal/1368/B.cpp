#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

const int m = 10;
const char s[] = "codeforces";

void solve(void)
{
	ll d;
	scanf("%lld",&d);
	
	int x = 0;
	for(int i=1; i<=100; ++i)
	{
		ll tmp = 1;
		for(int j=1; j<=m; ++j)
			tmp *= i;
		if(tmp < d) x = i;
		else break;
	}
	
	int y = 0;
	for(int i=0; i<=m; ++i)
	{
		ll tmp = 1;
		for(int j=1; j<=i; ++j)
			tmp *= (x + 1);
		for(int j=i+1; j<=m; ++j)
			tmp *= x;
		if(tmp < d) y = i;
		else break;
	}
	
	for(int i=0; i<m; ++i)
	{
		if(i<=y)
			for(int j=1; j<=x+1; ++j)
				putchar(s[i]);
		else
			for(int j=1; j<=x; ++j)
				putchar(s[i]);
	}
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}