#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[100105];
char s[100105];

char solve(int idx) {
    if (!s[idx]) { // I'm stupid
        int ok = 0;
        for (int ni = idx + a[idx]; ni < n; ni += a[idx])
            if (a[idx] < a[ni])
                ok |= (solve(ni) == 'B');
        for (int ni = idx - a[idx]; ni >= 0; ni -= a[idx])
            if (a[idx] < a[ni])
                ok |= (solve(ni) == 'B');
        s[idx] = (ok ? 'A' : 'B');
    }
    return s[idx];
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        solve(i);
    cout << s << endl;
}