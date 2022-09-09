#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	static int lst[30];
	memset(lst,0,sizeof(lst));
	for(int i=1; i<=n; ++i) lst[s[i] - 'a'] = i;
	
	string ans;
	static bool del[30];
	memset(del,0,sizeof(del));
	for(int i=1; i<=n; ++i)
	{
		if(del[s[i] - 'a']) continue;
		while(ans.size() && ans.back() < s[i] && lst[ans.back() - 'a'] > i)
			del[ans.back() - 'a'] = 0,
			ans.pop_back();
		ans += s[i]; del[s[i] - 'a'] = 1;
	}
	
	cout << ans << endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}