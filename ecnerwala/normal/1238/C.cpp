#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int Q; cin >> Q;
    while (Q--) {
        int H, N; cin >> H >> N;
        vector<int> P(N);
        for (int i = 0; i < N; i++) cin >> P[i];
        int ans = 0;
        P.push_back(0);
        for (int i = 1; i < N; i++) {
            if (P[i+1] == P[i]-1) {
                i++;
            } else {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}