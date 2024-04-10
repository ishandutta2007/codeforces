#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <string>
#include <cstring>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9+100;
const ll lINF = 1e18;
const double E = 2.718281828459045;

int n, m, a[111], b[111], mn = 0, ans;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    for (int i = 0; i < n; i++) {
        int j = mn;
        for (; j < m; j++) {
            if (abs(b[j] - a[i]) <= 1) {
                break;
            }
        }
        if (j < m) {
            mn = j+1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}