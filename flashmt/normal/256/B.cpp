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

long long count(long long n, long long x, long long y, long long turn)
{
	if (!turn) return 1;
	long long res = 0;
	long long xl = x - 1, xr = n - x, y0 = min(turn, y - 1), yy;
	
	yy = max(1LL, turn - xl);
	yy = min(yy, y0 + 1);
	res += (turn - y0 + turn - yy) * (y0 - yy + 1) / 2;
	res += (yy - 1) * xl;
	//cout << res << ' ' << y0 << ' ' << yy << endl;

	yy = max(1LL, turn - xr);
	yy = min(yy, y0 + 1);
	res += (turn - y0 + turn - yy) * (y0 - yy + 1) / 2;
	res += (yy - 1) * xr;
	//cout << res << ' ' << y0 << ' ' << yy << endl;

	y0 = min(turn, n - y);
	
	yy = max(1LL, turn - xl);
	yy = min(yy, y0 + 1);
	res += (turn - y0 + turn - yy) * (y0 - yy + 1) / 2;
	res += (yy - 1) * xl;
	//cout << res << ' ' << y0 << ' ' << yy << endl;

	yy = max(1LL, turn - xr);
	yy = min(yy, y0 + 1);
	res += (turn - y0 + turn - yy) * (y0 - yy + 1) / 2;
	res += (yy - 1) * xr;
	//cout << res << ' ' << y0 << ' ' << yy << endl;
	
	res += min(n, y + turn) - max(1LL, y - turn) + min(n, x + turn) - max(1LL, x - turn) + 1;
	//cout << turn << " = " << res << endl;
	return res;
}

int main()
{
	long long n, x, y, c;
	cin >> n >> x >> y >> c;

	long long low = 0, high = n * 3, ans;
	while (low <= high)
	{
		long long mid = (low + high)/2;
		if (count(n, x, y, mid) >= c) ans = mid, high = mid - 1;
		else low = mid + 1;
	}
	cout << ans << endl;
}