#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

char s[MAXN];

inline void chg(int n)
{
	static char t[MAXN];
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == '1') t[i] = '1';
		else if((s[i-1] == '1') ^ (s[i+1] == '1'))
			t[i] = '1';
		else t[i] = '0';
	}
	for(int i=1; i<=n; ++i) s[i] = t[i];
}

void solve(void)
{
	int n,m;
	scanf("%d%d%s",&n,&m,s+1);
	
	for(int i=1; i<=n && i<=m; ++i)
		chg(n);
	
	printf("%s\n",s+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}