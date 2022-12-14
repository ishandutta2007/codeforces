#include <bits/stdc++.h>

using namespace std;

int cnt[128];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        if (n % k) {
            cout << "-1\n";
            continue;
        }

        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) cnt[s[i]]++;

        bool trivial = true;
        for (int i = 'a'; i <= 'z'; i++) {
            if (cnt[i] % k) trivial = false;
        }

        if (trivial) {
            cout << s << '\n';
            continue;
        }

        int r = 0;
        for (int m = 'a'; m <= 'z'; m++) {
            if (cnt[m] % k != 0) r += k - cnt[m] % k;
        }

        int en;
        bool ok = false;
        for (int i = n - 1; i >= 0 && !ok; i--) {
            if (cnt[s[i]] % k == 1) r -= k - 1;
            else r++;
            cnt[s[i]]--;

            for (int j = s[i] + 1; j <= 'z'; j++) {
                if (cnt[j] % k == 0) r += k - 1;
                else r--;
                cnt[j]++;

                if (r <= n - i - 1) {
                    ok = true;
                    s[i] = j;
                    en = i + 1;

                    break;
                }

                cnt[j]--;
                if (cnt[j] % k == 0) r -= k - 1;
                else r++;
            }
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }

        int p = 'z';
        for (int i = n - 1; i >= en; i--) {
            for (;;) {
                if (p != 'a' && cnt[p] % k == 0) p--;
                else {
                    s[i] = p;
                    cnt[p]++;
                    break;
                }
            }
        }

        cout << s << '\n';
    }
}