#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef uint64_t ull;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int c = 0, sum = 0, total = 10;
    for (int i = 0; i < n; ++i) {
        total += a[i];
        if (total > 720) break;
        ++c;
        sum += max(total - 360, 0);
    }
    cout << c << " " << sum;
}