#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map> 
#define maxn 10000005
#define mod 1000000007
#define ll long long
using namespace std;
struct th
{
	int pl;
	ll num;
	bool operator < (const th &a)const
	{
		return pl < a.pl;
	}
}p[maxn]; // 
int a[maxn];
ll k;
int n; 
int up(int a, int b)
{
	int ans = a / b;
	if(a % b) ans++;
	return ans;
}
int main()
{
	scanf("%d%I64d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), k += (ll)a[i];
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int np = 0, nup = 0;
		for(int j = 1; up(a[i], j) >= j; j++)
		{
			int ns = up(a[i], j);
			nup = ns;
			p[cnt].pl = j, p[cnt++].num = ns - np;
			np = ns;
		}
		for(int j = nup - 1; j >= 1; j--)
		{
			int pl = a[i] / j;
			if(a[i] % j) pl++;
			p[cnt].pl = pl, p[cnt++].num = j - np;
			np = j;
		}
	}
	sort(p, p + cnt);
	ll nplus = 0;
	ll ans = p[0].pl - 1;

	for(int i = 0; i < cnt; i++)
	{
		nplus += p[i].num;
		if(i != cnt - 1 && p[i + 1].pl == p[i].pl) continue;
		ll nans = k / nplus;
	//	cout<<p[i].pl<<" "<<nplus<<endl;
		if(nans >= p[i].pl)
			ans = nans;
	}
	printf("%I64d\n", ans);
	return 0;
 }