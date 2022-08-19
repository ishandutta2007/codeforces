#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define maxn 12
#define ll long long
using namespace std; 
char s[maxn];
int nm[maxn];
bool can[maxn];
ll cnt[maxn]; 
int pw[maxn];
ll ans = -1;
int ns[maxn];
bool hv[maxn];
void dfs(int a)
{
	if(a == 10)
	{
		ll nans = 0;
		for(int i = 0; i < 10; i++)
			nans += cnt[i] * (ll)ns[i];
		if(ans == -1 || nans < ans)
			ans = nans;
		return;
	}
	for(int i = 0; i < 10; i++)
	{
		if(hv[i]) continue;
		if(!i && !can[a]) continue;
		ns[a] = i, hv[i] = 1, dfs(a + 1), hv[i] = 0;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	pw[0] = 1;
	can[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * 10, 
		can[i] = 1;
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		can[s[0] - 'a'] = 0;
		int l = strlen(s);
		for(int i = 0; i < l; i++)
			cnt[s[i] - 'a'] += pw[l - i - 1];
	}
	dfs(0);
	printf("%I64d\n", ans);
	return 0;
}