#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 10 + 5;
const int MAXM = 10 + 5;

int n,m;
char s[MAXN][MAXM], t[MAXM];

inline bool check(void)
{
	for(int i=1; i<=n; ++i)
	{
		int cnt=0;
		for(int j=1; j<=m; ++j)
			if(s[i][j] != t[j])
			{
				++cnt;
				if(cnt>1) return 0;
			}
	}
	return 1;
}

void solve(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
	
	for(int i=1; i<=m; ++i)
		t[i] = s[1][i];
	t[m+1]=0;
	
	if(check()){ printf("%s\n",t+1); return;}
	
	for(int i=1; i<=m; ++i)
	{
		char lst = t[i];
		for(char& k=t[i]='a'; k<='z'; ++k)
		{
			if(k==lst) continue;
			if(check()){ printf("%s\n",t+1); return;}
		}
		t[i]=lst;
	}
	printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}