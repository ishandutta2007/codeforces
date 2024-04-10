/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn], vis[maxn], id[maxn];
map<int, int> buc;
int cnt[maxn], top;
//priority_queue<int> q;
void solve()
{
	n = read(), k = read();
	buc.clear();
	ru(i, 1, n) buc[a[i] = read()] = 1;
	sort(a + 1, a + n + 1);
	int now = 0, mex = 0;
	while(now <= k && mex <= a[n - k])
	{
		if(!buc[mex])
		{
			now++;
			if(now > k) break;
		}
		mex++;
	}
	if(mex > a[n - k]) {printf("0\n"); return;}
	buc.clear();
	ru(i, 1, n) if(a[i] >= mex) buc[a[i]]++;
	top = 0;
	for (auto x: buc) cnt[++top] = x.second;
	sort(cnt + 1, cnt + top + 1, greater<int>());
	rd(i, top, 1)
	{
		if(k < cnt[i]) {printf("%d\n", i); return;}
		k -= cnt[i];
	}
	printf("0\n");
}
int main()
{
	int T = read(); while(T--) solve(); 
	return 0;
}