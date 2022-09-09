#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	string s;
	cin >> s;
	
	int cnt = 0;
	for(char c: s)
	{
		cnt += c == 'A'? 1: -1;
		if(cnt < 0) break;
	}
	if(s.back() != 'B') cnt = -1;
	
	if(cnt < 0) printf("NO\n");
	else printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}