#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long ll;

int tp;

long long n;

int ask(ll i,ll j)
{
	cout << i << ' ' << j << endl;
	fflush(stdout);
	cin >> tp;
	if (tp == 0)
		exit(0);
	return tp;
}

void dfs1(ll la,ll ra,ll lb,ll rb);

void dfs2(ll la,ll ra,ll lb,ll rb,ll limx,ll limy)
{
//	cout << la << ' ' << ra << ' ' << lb << ' ' << rb << ' ' << limx << ' ' << limy << endl;
	if (la > limx)
		dfs1(la,ra,lb,limy);
	if (lb > limy)
		dfs1(la,limx,lb,rb);
	ll x = la + (limx - la) * 3 / 4;
	ll y = lb + (limy - lb) * 3 / 4;
	int res = ask(x,y);
	if (res == 1)
		dfs2(x + 1,ra,lb,rb,limx,limy);
	if (res == 2)
		dfs2(la,ra,y + 1,rb,limx,limy);
	if (res == 3)
		dfs2(la,ra,lb,rb,x,y);
}

void dfs1(ll la,ll ra,ll lb,ll rb)
{
//	cout << la << ' ' << ra << ' ' << lb << ' ' << rb << endl;
	if (la == ra && lb == rb)
		ask(la,lb);
	ll x = la + (ra - la) / 4;
	ll y = lb + (rb - lb) / 4;
	int res = ask(x,y);
	if (res == 1)
		dfs1(x + 1,ra,lb,rb);
	if (res == 2)
		dfs1(la,ra,y + 1,rb);
	if (res == 3)
		dfs2(la,ra,lb,rb,x,y);
}

int main()
{
	cin >> n;
	dfs1(1,n,1,n);
	return 0;
}