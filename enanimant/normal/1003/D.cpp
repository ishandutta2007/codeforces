#include <bits/stdc++.h>

using namespace std;


const int MAXN = (int) 2e5;
const double EPS = 1e-6;

int N, Q;
int cnt[31];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;

        cnt[(int) (log2(t) + EPS)]++;
    }


    while (Q--) {
        int b; cin >> b;

        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            int used = min(cnt[i], b / (1 << i));
            b -= used << i;
            ans += used;
        }

        cout << (b == 0 ? ans : -1) << '\n';
    }


    return 0;
}