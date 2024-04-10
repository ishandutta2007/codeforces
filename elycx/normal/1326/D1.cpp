#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define uint unsigned int
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1000005
using namespace std;
const int mod1 = 123984337;
const int bas1 = 1e9 + 7;
const uint bas2 = 1e9 + 9;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n;
char s[maxn];
int ans, pre, suf;
int hp1[maxn], hp2[maxn];
uint hs1[maxn], hs2[maxn];
int pow1[maxn];
uint pow2[maxn];
inline int check(int l1, int r1, int l2, int r2)
{
	if(l1 <= 0 || r2 > n) return 0;
	if(l1 > r1) return 1;
	if((hp1[r2] + mod1 - (ll)hp1[l2 - 1] * pow1[r2 - l2 + 1] % mod1) % mod1 != (hs1[l1] + mod1 - (ll)hs1[r1 + 1] * pow1[r1 - l1 + 1] % mod1) % mod1) return 0;
	if(hp2[r2] - hp2[l2 - 1] * pow2[r2 - l2 + 1] != hs2[l1] - hs2[r1 + 1] * pow2[r1 - l1 + 1]) return 0;
	return 1;
}
void solve()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	pow1[0] = 1, pow2[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		pow1[i] = (ll)pow1[i - 1] * bas1 % mod1;
		pow2[i] = pow2[i - 1] * bas2;
	}
	hp1[0] = hp2[0] = hs1[n + 1] = hs2[n + 1] = 0;
	for (int i = 1; i <= n; i++)
	{
		hp1[i] = ((ll)hp1[i - 1] * bas1 % mod1 + s[i] - 'a') % mod1;
		hp2[i] = hp2[i - 1] * bas2 + s[i] - 'a';
//		cout<<hp1[i]<<" ";
	}
//	cout<<endl;
	for (int i = n; i >= 1; i--)
	{
		hs1[i] = ((ll)hs1[i + 1] * bas1 + s[i] - 'a') % mod1;
		hs2[i] = hs2[i + 1] * bas2 + s[i] - 'a';
//		cout<<hs1[i]<<" ";
	}
//	cout<<endl;
//	printf("!!!%d\n", check(4, 4, 6, 6));
	ans = pre = 1, suf = n + 1;
	int now = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		if(now == i - 1 && s[i] == s[n - i + 1]) now++;
//		printf("%d %d\n", i, now);
		if(check(now + 1, i, i + 1, i + i - now)) 
		{
			if(2 * i > ans)
			{
				ans = 2 * i;
				suf = n - now + 1;
				pre = suf + ans - n - 1;
			}
		}
		if(2 * i + 1 > n) continue;
//		printf("%d %d %d %d\n", now + 1, i, i + 2, now + 2 * i )
		if(check(now + 1, i, i + 2, i + i - now + 1)) 
		{
//			printf("!%d\n", i);
			if(2 * i + 1 > ans)
			{
				ans = 2 * i + 1;
				suf = n - now + 1;
				pre = suf + ans - n - 1;
			}
		}
	} 
//	printf("\n");
	now = n + 1;
	for (int i = n; i >= n - n / 2 + 1; i--)
	{
//		printf("%d %d\n", i, now);
		if(now == i + 1 && s[i] == s[n - i + 1]) now--;
		if(check(i + i - now, i - 1, i, now - 1)) 
		{
			if(2 * (n - i + 1) > ans)
			{
				ans = 2 * (n - i + 1);
				pre = n - now + 1;
				suf = pre + n + 1 - ans;
			}
		}
		if(2 * (n - i + 1) + 1 > n) break;
		if(check(i + i - now - 1, i - 2, i, now - 1))
		{
			if(ans < 2 * (n - i + 1) + 1)
			{
				ans =  2 * (n - i + 1) + 1;
				pre = n - now + 1;
				suf = pre + n + 1 - ans;
			} 
		}
	} 
//	printf("%d %d\n", pre, suf);
	char t[maxn];
	int cnt = 0;
	for (int i = 1; i <= pre; i++) t[++cnt] = s[i];
	for (int i = suf; i <= n; i++) t[++cnt] = s[i];
//	for (int i = 1; i <= cnt; i++)
//	{
//		if(t[i] != t[cnt - i + 1]) return;
//	}
	for (int i = 1; i <= cnt; i++) printf("%c", t[i]);
	printf("\n");
} 
int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}