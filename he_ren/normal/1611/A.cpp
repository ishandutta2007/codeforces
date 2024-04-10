#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	string s;
	cin >> s;
	if((s.back() - '0') % 2 == 0)
	{
		printf("0\n");
	}
	else if((s[0] - '0') % 2 == 0)
	{
		printf("1\n");
	}
	else
	{
		bool ok = 0;
		for(char c: s)
			if((c - '0') % 2 == 0) ok = 1;
		if(ok) printf("2\n");
		else printf("-1\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}