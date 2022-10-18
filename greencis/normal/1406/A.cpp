#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;



int main() {
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<int> cnt(105);
        while (n--) {
            int x;
            cin >> x;
            ++cnt[x];
        }
        int ans = 0;
        for (int z = 2; z--; ) {
            for (int i = 0; i < 105; ++i) {
                if (cnt[i]) --cnt[i];
                else {
                    ans += i;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}