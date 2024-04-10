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

char a[1111][1111];
bool g[1111];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool pos = true;
        for (int j = 1; j < n; j++) {
            if (a[j][i] < a[j-1][i] && g[j] != 1) {
                pos = false;
                break;
            }
        }
        if (pos) {
            ans++;
            for (int j = 1; j < n; j++) {
                if (a[j][i] > a[j-1][i]) {
                    g[j] = true;
                }
            }
        }
    }
    cout << m-ans << endl;
    return 0;
}