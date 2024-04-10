#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+5;

int t[ms];
int existe[ms];
int qnt[ms];

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, T;
    cin >> n >> T;
    n = min(n, T - 1);
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for(int i = 1; i < n; i++) {
        t[n-i] += i;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(t[i] < T) {
            ans++;
            existe[i] = 1;
        } else if(t[i] < T + n - i) {
            existe[i] = 1;
            qnt[t[i] - T]++;
        }
    }
    int best = ans;
    for(int i = n; i > 0; i--) {
        best = max(best, ans);
        if(existe[i]) ans--;
        ans += qnt[n-i];
    }
    cout << best << '\n';
}