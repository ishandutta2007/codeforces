#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	if(n&1){ printf("NO\n"); return;}
	
	int cnt = 0, l, mid, r;
	char fir = 0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == '?') ++cnt;
		if(s[i] == '(' || s[i] == ')')
		{
			if(!fir) fir = s[i], l = cnt;
			else mid = cnt;
			cnt = 0;
		}
	}
	r = cnt;
	if(fir == '(')
	{
		l %= 2; mid %= 2; r %= 2;
		if(l + mid + r == 2 || l + mid + r == 0) printf("YES\n");
		else printf("NO\n");
	}
	else
	{
		if(!l || !r){ printf("NO\n"); return;}
		l %= 2; mid %= 2; r %= 2; l ^= 1; r ^= 1;
		if(l ^ mid ^ r) printf("NO\n");
		else printf("YES\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}