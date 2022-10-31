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

int n, a[1000010];
ll gr, ls;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i>=1) {
            ll ngr, nls;
            ngr=nls=max(gr, ls);
            if (a[i]>a[i-1]) ngr=max(ngr, gr+a[i]-a[i-1]);
            if (a[i]<a[i-1]) nls=max(nls, ls+a[i-1]-a[i]);
            gr=ngr;
            ls=nls;
        }
    }
    cout << max(gr, ls);
    return 0;
}