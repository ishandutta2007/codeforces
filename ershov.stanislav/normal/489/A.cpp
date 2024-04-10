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

int n, a[3333];
vector<pair<int, int> > ans;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        pair<int, int> mn = mp(INF, 0);
        for (int j = i; j < n; j++) {
            mn = min(mn, mp(a[j], j));
        }
        if (mn.sc != i) {
            ans.pb (mp(i, mn.sc));
            swap(a[i], a[mn.sc]);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].fs << ' ' << ans[i].sc << endl;
    }
    return 0;
}