#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x - 1] += 1;
    }
    cout << n - *max_element(cnt, cnt + 3) << "\n";
    return 0;
}