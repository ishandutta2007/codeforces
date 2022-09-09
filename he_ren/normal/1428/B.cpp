#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s);
	
	bool flag0=0, flag1=0;
	for(int i=0; i<n; ++i)
	{
		if(s[i] == '>') flag0 = 1;
		if(s[i] == '<') flag1 = 1;
	}
	if(!flag0 || !flag1)
	{
		printf("%d\n",n);
		return;
	}
	
	int ans = 0;
	s[n] = s[0];
	for(int i=0; i<n; ++i)
		if(s[i] == '-' || s[i+1] == '-') ++ans;
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}