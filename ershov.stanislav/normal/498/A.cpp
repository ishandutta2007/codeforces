#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;

#ifdef DEBUG
#define dout(x) cerr<<x;
#else
#define dout(x)
#endif

using namespace std;

int n;

ll xx1, yy1, xx2, yy2;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> xx1 >> yy1 >> xx2 >> yy2;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a*xx1 + b*yy1 + c <0 && a*xx2 + b*yy2 + c > 0) ans++;
        if (a*xx1 + b*yy1 + c >0 && a*xx2 + b*yy2 + c < 0) ans++;
    }
    cout << ans;
    return 0;
}