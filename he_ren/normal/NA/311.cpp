#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 100 + 5;

int m = 7;
const char tt[10] = "abacaba";
char s[MAXN], t[MAXN];

bool eq(char *s)
{
	for(int i=0; i<m; ++i)
		if(s[i] != '?' && s[i] != tt[i])
			return 0;
	return 1;
}

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	t[n+1] = 0;
	
	for(int i=1; i+m-1<=n; ++i)
	{
		if(!eq(s+i)) continue;
		for(int j=1; j<=n; ++j) t[j] = s[j];
		for(int j=0; j<m; ++j)
			t[i+j] = tt[j];
		for(int j=1; j<=n; ++j)
			if(t[j]=='?') t[j] = 'z';
		
		bool flag = 1;
		for(int j=1; j+m-1<=n; ++j) if(j!=i)
			if(eq(t+j)){ flag=0; break;}
		if(flag)
		{
			printf("Yes\n");
			printf("%s\n",t+1);
			return;
		}
	}
	printf("No\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}