#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN], t[MAXN];
bool rev;

vector<int> ans;

void solve(void)
{
	int n;
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1; i<=n; ++i)
		s[i] -= '0',
		t[i] -= '0';
	
	ans.clear();
	rev = 0;
	int fir = 1, now = n;
	for(int i=n; i>1; --i)
	{
		int sx = s[now] ^ rev;
		if(sx == t[i])
		{
			if(rev) ++now;
			else --now;
			continue;
		}
		
		if((s[fir]^rev) == t[i]) ans.push_back(1), s[fir]^=1;
		rev^=1; ans.push_back(i); swap(now, fir);
		
		if(rev) ++now;
		else --now;
	}
	if((s[fir]^rev) != t[1]) ans.push_back(1);
	
	printf("%d ",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i) printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}