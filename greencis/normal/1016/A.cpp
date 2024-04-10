#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, x;
ll cur;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    while (n--) {
        cin >> x;
        int ans = (cur + x) / m - (cur) / m;
        cur += x;
        cout << ans << " ";
    }
}