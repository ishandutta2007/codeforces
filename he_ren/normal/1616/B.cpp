#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	auto print = [&] (int pos)
	{
		for(int i=1; i<=pos; ++i)
			putchar(s[i]);
		for(int i=pos; i>=1; --i)
			putchar(s[i]);
		printf("\n");
	};
	
	if(s[1] == s[2])
	{
		print(1);
		return;
	}
	
	for(int i=1; i<n; ++i)
		if(s[i] < s[i+1])
		{
			print(i);
			return;
		}
	print(n);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}