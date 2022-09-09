#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	auto get = [&] (int x)
	{
		if(x < 1 || x > n) return false;
		return s[x-1] == 'a' && s[x] == 'b' && s[x+1] == 'c';
	};
	
	int ans = 0;
	for(int i=1; i<=n; ++i) ans += get(i);
	
	while(Q--)
	{
		int pos;
		static char t[10];
		scanf("%d%s",&pos,t+1);
		ans -= get(pos) + get(pos-1) + get(pos+1);
		s[pos] = t[1];
		ans += get(pos) + get(pos-1) + get(pos+1);
		printf("%d\n",ans);
	}
}

int main(void)
{
	int T = 1;
//	scanf("%d",&T);
	while(T--) solve();
	return 0;
}