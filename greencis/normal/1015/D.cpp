#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll n, k, s;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k >> s;
    if (s < k || s > k * (n - 1)) { cout << "NO"; return 0; }
    cout << "YES\n";
    int cur = 1;
    bool backwards = false;
    for (; k > 0; --k) {
        int step = (s + k - 1) / k;
        if (backwards)
            cur -= step;
        else
            cur += step;
        backwards ^= 1;
        s -= step;
        cout << cur << " ";
    }
}