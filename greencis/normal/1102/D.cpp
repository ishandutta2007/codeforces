#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

char s[500106];
int n, cnt[3];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        ++cnt[s[i] - 48];
    for (int i = 0; i < n && cnt[0] < n / 3; ++i) {
        if (s[i] == '1' && cnt[1] > n / 3) {
            --cnt[1];
            ++cnt[0];
            s[i] = '0';
        } else if (s[i] == '2' && cnt[2] > n / 3) {
            --cnt[2];
            ++cnt[0];
            s[i] = '0';
        }
    }
    for (int i = n; i-- > 0 && cnt[0] > n / 3; ) {
        if (s[i] == '0') {
            --cnt[0];
            if (cnt[2] < n / 3) {
                ++cnt[2];
                s[i] = '2';
            } else if (cnt[1] < n / 3) {
                ++cnt[1];
                s[i] = '1';
            }
        }
    }

    for (int i = 0; i < n && cnt[1] < n / 3; ++i) {
        if (s[i] == '2') {
            --cnt[2];
            ++cnt[1];
            s[i] = '1';
        }
    }
    for (int i = n; i-- > 0 && cnt[1] > n / 3; ) {
        if (s[i] == '1') {
            --cnt[1];
            ++cnt[2];
            s[i] = '2';
        }
    }

    cout << s << endl;
}