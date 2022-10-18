#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
ll ans = 0;
char a[1001005], b[1001005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> a >> b;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] == '0' && a[i + 1] == '1' && b[i] == '1' && b[i + 1] == '0' ||
            a[i] == '1' && a[i + 1] == '0' && b[i] == '0' && b[i + 1] == '1') {
            ++ans;
            swap(a[i], a[i + 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ++ans;
            a[i] ^= 1;
        }
    }
    cout << ans << endl;
}