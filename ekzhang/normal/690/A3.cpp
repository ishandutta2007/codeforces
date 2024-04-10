#include <bits/stdc++.h>
using namespace std;

int T;
int N, R;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> R;
        int ans = N * N + R;
        for (int i = 0; i < N - 1; i++) {
            int a; cin >> a;
            ans -= a;
        }
        cout << (ans % N) + 1 << '\n';
    }
    cout.flush();
    return 0;
}