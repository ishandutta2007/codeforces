#include <bits/stdc++.h>

using namespace std;


int N;
int a[101];

int main() {
    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        a[t]++;
        ans = max(ans, a[t]);
    }

    cout << ans << '\n';

    return 0;
}