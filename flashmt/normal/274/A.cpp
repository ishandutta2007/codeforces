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

map <int,int> m;

int main()
{
	int a[100100], f[100100], cnt[100100], n, k;
	cin >> n >> k;
	rep(i, n) cin >> a[i];
	sort(a, a + n);
	rep(i, n) m[a[i]] = i;
	rep(i, n)
	{
		f[i] = i; cnt[i] = 1;
		if (a[i] % k == 0 && m.count(a[i] / k)) f[i] = f[m[a[i] / k]], cnt[f[i]]++;
	}
	
	int ans = 0;
	rep(i, n)
		if (f[i] == i) ans += (cnt[i] + 1) / 2;
	cout << ans << endl;
}