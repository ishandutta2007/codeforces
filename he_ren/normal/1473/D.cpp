#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];

int val[MAXN], premx[MAXN], premn[MAXN], sufmx[MAXN], sufmn[MAXN];

void solve(void)
{
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	for(int i=1; i<=n; ++i)
	{
		val[i] = val[i-1] + (s[i] == '+'? 1: -1);
		premx[i] = max(val[i], premx[i-1]);
		premn[i] = min(val[i], premn[i-1]);
	}
	
	sufmx[n+1] = sufmn[n+1] = 0;
	for(int i=n; i>=1; --i)
	{
		sufmx[i] = sufmx[i+1];
		sufmn[i] = sufmn[i+1];
		if(s[i] == '+') ++sufmx[i], sufmn[i] = min(0, sufmn[i] + 1);
		else --sufmn[i], sufmx[i] = max(0, sufmx[i] - 1);
	}
	
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		int mx = premx[l-1], mn = premn[l-1];
		mx = max(mx, val[l-1] + sufmx[r+1]);
		mn = min(mn, val[l-1] + sufmn[r+1]);
		printf("%d\n",mx - mn + 1);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}