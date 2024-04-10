#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int Q; cin >> Q;
    while (Q--) {
        int N, R; cin >> N >> R;
        vector<int> X(N);
        for (int i = 0; i < N; i++) cin >> X[i];
        sort(X.begin(), X.end());
        N = int(unique(X.begin(), X.end()) - X.begin());
        X.resize(N);
        reverse(X.begin(), X.end());
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (X[i] - i * R <= 0) break;
            ans++;
        }
        cout << ans << '\n';
    }
}