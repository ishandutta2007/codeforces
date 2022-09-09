#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;

int n;
char s[MAXN][MAXN];

int f[MAXN];
inline pii get(int x,int y,int k)
{
	if(x == 1)
	{
		if(y % 2) ++y;
		return make_pair(y, k);
	}
	
	if((x + y) % 2)
	{
		int t = min(x - 1, y - 1);
		x -= t; y -= t; k ^= t&1;
	}
	else
	{
		int t = min(x - 1, n - y);
		x -= t; y += t; k ^= t&1;
	}
	
	if(x != 1) x = n - x + 1, y = n - y + 1;
	return get(x, y, k);
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%s",s[i] + 1);
	
	if(n % 2) return printf("NONE"), 0;
	
	memset(f, -1, sizeof(f));
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) if(s[i][j] != '.')
		{
			pii res = get(i, j, s[i][j] == 'G');
			int y = res.first, k = res.second;
			if(f[y] == -1) f[y] = k;
			else if(f[y] != k)
				return printf("NONE"), 0;
		}
	
	for(int i=2; i<=n; i+=2)
		if(f[i] == -1) return printf("MULTIPLE"), 0;
	
	printf("UNIQUE\n");
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=n; ++j)
		{
			pii res = get(i, j, 0);
			int k = f[res.first] ^ res.second;
			putchar("SG"[k]);
		}
	return 0;
}