#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 18 + 5;

inline int calc(char s[],int n)
{
	int res = 0;
	for(int i=1; i<=n; ++i)
		res += s[i] - '0';
	return res;
}

inline void add(char s[],int n,int i)
{
	while(i>=1 && s[i] == '9')
		s[i] = '0',
		--i;
	if(i>=1) ++s[i];
}

char s[MAXN];

void solve(void)
{
	int x;
	scanf("%s%d",s+1,&x);
	int n = strlen(s+1);
	
	if(calc(s,n) <= x){ printf("0\n"); return;}
	
	ll cost = 1, ans = 0;
	for(int i=n; i>=1; --i)
	{
		while(s[i] != '0')
			ans += cost,
			add(s,n,i);
		if(calc(s,n) <= x){ printf("%lld\n",ans); return;}
		cost *= 10;
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}