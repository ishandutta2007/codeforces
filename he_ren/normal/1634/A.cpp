#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,d;
	string s;
	cin >> n >> d >> s;
	string rs(s.rbegin(), s.rend());
	
	if(rs == s || d == 0)
	{
		printf("1\n");
		return;
	}
	else printf("2\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}