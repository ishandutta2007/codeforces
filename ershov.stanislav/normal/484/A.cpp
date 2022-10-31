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

#define PROBLEM "test"
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#ifdef DEBUG
#define ddd(x) cerr << (x) << ' '
#else
#define ddd(x)
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double E = 2.718281828459045;

int n;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        for (int j = 61; j>=0; j--) {
            //cout << (r&(1ll<<j)) << ' ' << (l&(1ll<<j)) << endl;
            if (( (l&(1ll<<j)) != ( (r&(1ll<<j)) ) ) && j!=0) {
                if (r == ( (l^(l&((1ll<<j) - 1))) ^ ((1ll<<(j+1)) - 1) )) cout << r << endl;

                else cout << ( (l^(l&((1ll<<j) - 1))) ^ ((1ll<<j) - 1) ) << endl;
                break;
            }
            if (j == 0) cout << r << endl;
        }
    }
    return 0;
}