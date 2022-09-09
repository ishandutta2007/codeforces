#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	string s;
	cin >> s;
	
	vector<int> t(26);
	for(char c: s)
	{
		if(c >= 'a' && c <= 'z') t[c - 'a'] = 1;
		else if(!t[c - 'A'])
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}