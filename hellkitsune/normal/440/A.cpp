#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
bool was[100005] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n - 1) {
        int x;
        cin >> x;
        was[x] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (!was[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}