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

int n, a[111111], cnt[111111], b[111111];
set<int> s[111111], r[111111];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        cnt[a[i]]++;
    }
    int cntodd = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i]%2) cntodd++;
    }
    if (cntodd >= 2) {
        cout << "0\n";
        return 0;
    }
    int diff = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[n-i-1]) {
            diff = i;
            break;
        }
    }
    if (diff == -1) {
        cout << n * 1ll * (n+1) * 1ll / 2 << endl;
        return 0;
    }
    for (int i = n-diff-1; i>=diff; i--) {
        s[a[i]].insert(i);
    }
    int mx1 = 0, mn2 = n;
    for (int i = diff; i<=n/2; i++) {
        if (a[i] != a[n-i-1]) {
            int nxt = *s[a[n-i-1]].begin();
            mx1 = max(mx1, max(i, nxt));
            s[a[n-i-1]].erase(nxt);
            s[a[i]].erase(i);
            s[a[i]].insert(nxt);
            swap(a[i], a[nxt]);
        } else {
            s[a[i]].erase(i);
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }


    for (int i = diff; i<n-diff; i++) {
        r[a[i]].insert(n-i);
    }
    for (int i = n-diff-1; i>=n/2; i--) {
        if (a[i] != a[n-i-1]) {
            int nxt = n-(*r[a[n-i-1]].begin());
            mn2 = min(mn2, min(i, nxt));
            r[a[n-i-1]].erase(n-nxt);
            r[a[i]].erase(n-i);
            r[a[i]].insert(n-nxt);
            swap(a[i], a[nxt]);
        } else {
            r[a[i]].erase(n-i);
        }
    }
    cout << (diff+1)*1ll*(n-mx1) + (diff+1)*1ll*(mn2+1)  - (diff+1)*1ll*(diff+1) << endl;
    return 0;
}