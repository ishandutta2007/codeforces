#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

char s[MAXN];

void solve(void)
{
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		bool ok = 0;
		for(int i=1; i<l && !ok; ++i)
			if(s[i] == s[l]) ok = 1;
		for(int i=r+1; i<=n && !ok; ++i)
			if(s[i] == s[r]) ok = 1;
		
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}