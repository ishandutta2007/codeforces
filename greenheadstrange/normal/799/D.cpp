#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set> 
#define maxn 100005
using namespace std;
int xs[maxn];
struct th
{
	int id, a, b, ans;
	th(int x, int y, int z){id = x, a = y, b = z;}
	bool operator < (const th &x)const
	{
		if(id != x.id) return id < x.id;
		if(a != x.a) return a < x.a;
		return b < x.b;
	}
};
int cnt;
set <th> q;
int up(int a, int b)
{
	if(!(a % b)) return a / b;
	return a / b + 1;
}
int solve(int id, int a, int b)
{
	if(a > b) swap(a, b);
	if(a == 1 && b == 1) return 0;
	if(id >= cnt || id >= 40) return maxn;
	th new1 = th(id, a, b);
	set <th> :: iterator it = q.find(new1);
	if(it != q.end()) return (*it).ans;
	new1.ans = 1 + min(solve(id + 1, up(a, xs[id]), b), solve(id + 1, a, up(b, xs[id])));
	q.insert(new1);
	return new1.ans;
}
int a, b, h, w, n;
int main()
{
	scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
	for(int i = 0; i < n; i++)
	{
		int inp;
		scanf("%d", &inp);
		xs[cnt++] = inp;
	}
	sort(xs, xs + cnt);
	for(int i = 0; cnt - 1 - i > i; i++)
		swap(xs[i], xs[cnt - 1 - i]); 
	int ans = min(solve(0, up(a, h), up(b, w)), solve(0, up(a, w), up(b, h)));
	if(ans > maxn) 
	{
		puts("-1");
		return 0;
	}
	printf("%d\n", ans);
	return 0;
 }