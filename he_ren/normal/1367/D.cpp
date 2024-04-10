#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 50 + 5;

char s[MAXN];
int b[MAXN];
char ans[MAXN];

int cnt[30 + 5];

void solve(void)
{
	int m;
	scanf("%s%d",s+1,&m);
	int n = strlen(s+1);
	for(int i=1; i<=m; ++i)
		scanf("%d",&b[i]);
	
	for(int i=0; i<26; ++i) cnt[i] = 0;
	for(int i=1; i<=n; ++i)
		++cnt[s[i]-'a'];
	
	memset(ans,0,sizeof(ans));
	int now = 25, rem = m;
	while(rem)
	{
		static vector<int> pos;
		
		pos.clear();
		for(int i=1; i<=m; ++i)
			if(!ans[i] && !b[i])
				pos.push_back(i);
		
		while(cnt[now] < (int)pos.size()) --now;
		
		for(int i=0; i<(int)pos.size(); ++i)
			ans[pos[i]] = now + 'a';
		
		for(int i=0; i<(int)pos.size(); ++i)
		{
			int x = pos[i];
			
			for(int j=1; j<x; ++j)
				if(!ans[j]) b[j] -= x-j;
			for(int j=x+1; j<=m; ++j)
				if(!ans[j]) b[j] -= j-x;
		}
		
		rem -= (int)pos.size();
		--now;
	}
	printf("%s\n",ans+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}