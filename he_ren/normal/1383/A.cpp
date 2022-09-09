#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN], t[MAXN];

bool to[25][25];

void solve(void)
{
	int n;
	scanf("%d%s%s",&n,s+1,t+1);
	
	for(int i=1; i<=n; ++i)
	{
		if(s[i] > t[i])
		{
			printf("-1\n");
			return;
		}
	}
	
	int ans = 0;
	for(char c='a'; c<='t'; ++c)
	{
		static vector<int> a;
		a.clear();
		
		for(int i=1; i<=n; ++i) if(s[i] == c)
			if(t[i] > s[i])
				a.push_back(t[i]);
		if(!a.size()) continue;
		
		sort(a.begin(),a.end());
		
		for(int i=1; i<=n; ++i) if(s[i] == c)
			if(t[i] > s[i])
				s[i] = a[0];
		++ans;
	}
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}