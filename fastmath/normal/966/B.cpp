#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <random>
#include <time.h>
#include <bitset>

using namespace std;
#define int long long

vector <pair <int, int> > a;

void solve(int n, int x1, int x2, bool t) {
    int best = -1;
    for (int i = n - 1; i >= 0; --i) {
        int k = n - i;
        int want = (x2 - 1) / k + 1;
        if (want <= a[i].first) {
            best = i;
            break;
        }
    }

    for (int len = 1; len < n; ++len) {
        int want = (x1 - 1) / len + 1;

        int l, r;

        l = -1;
        r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (a[m].first < want) {
                l = m;
            }
            else {
                r = m;
            }
        }

        if (n - r < len) continue;
        
        int tl = r;
        int tr = r + len - 1;

        if (tr < best) {
            cout << "Yes\n";

            if (!t) {
                cout << len << ' ' << n - best << '\n';
                for (int i = tl; i <= tr; ++i) cout << a[i].second + 1 << ' ';
                cout << '\n';
                for (int i = best; i < n; ++i) cout << a[i].second + 1 << ' ';
                cout << '\n';
            }
            else {
                cout << n - best << ' ' << len << '\n';
                for (int i = best; i < n; ++i) cout << a[i].second + 1 << ' ';
                cout << '\n';
                for (int i = tl; i <= tr; ++i) cout << a[i].second + 1 << ' ';
                cout << '\n';
           }
                            
            exit(0);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x1, x2;
    cin >> n >> x1 >> x2;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    solve(n, x1, x2, 0);
    solve(n, x2, x1, 1);
    
    cout << "No\n";
    return 0;
}