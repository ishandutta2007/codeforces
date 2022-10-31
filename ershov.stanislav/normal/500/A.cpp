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
int t;
bool pos[555555];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n;
    cin >> t;
    pos[0] = true;
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        if (pos[i]) {
            pos[i + a] = true;
        }
    }
    if (pos[t - 1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}