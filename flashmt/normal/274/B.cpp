#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

vector <int> a[100100];
int n, v[100100];

pair <long long, long long> go(int x, int par)
{
	long long pos = 0, neg = 0;
	rep(i, sz(a[x]))
	{
		int y = a[x][i];
		if (y == par) continue;
		pair <long long, long long> u = go(y, x);
		pos = max(pos, u.first);
		neg = max(neg, u.second);
	}
	long long val = pos - neg + v[x];
	if (val < 0) return make_pair(pos - val, neg);
	return make_pair(pos, neg + val);
}

int main()
{
	int x, y;
	cin >> n;
	rep(i, n - 1)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	fr(i, 1, n) cin >> v[i];
	pair <long long, long long> ans = go(1, 0);
	cout << ans.first + ans.second << endl;
}