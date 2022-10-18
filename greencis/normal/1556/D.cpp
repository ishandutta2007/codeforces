#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int ALL = (1 << 30) - 1;
int a[12345];
int known_bits[12345];
int ori[12345];
int andi[12345];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i + 1 < n; ++i) {
        cout << "or " << i + 1 << " " << i + 2 << endl;
        cin >> ori[i];

        cout << "and " << i + 1 << " " << i + 2 << endl;
        cin >> andi[i];

        int cur_known = ALL ^ ori[i] ^ andi[i];
        a[i] |= ori[i] & cur_known;
        known_bits[i] |= cur_known;
        a[i + 1] |= ori[i] & cur_known;
        known_bits[i + 1] |= cur_known;
    }
    {
        cout << "or 1 3" << endl;
        int or02;
        cin >> or02;

        cout << "and 1 3" << endl;
        int and02;
        cin >> and02;

        int cur_known = ALL ^ or02 ^ and02;
        a[0] |= or02 & cur_known;
        known_bits[0] |= cur_known;
        a[2] |= or02 & cur_known;
        known_bits[2] |= cur_known;
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i + 1 < n; ++i) {
            int can_set_to_0 = known_bits[i + 1] & ~known_bits[i];
            if (can_set_to_0) {
                changed = true;
                a[i] |= ~a[i + 1] & can_set_to_0;
                known_bits[i] |= can_set_to_0;
            }

            int can_set_to_1 = known_bits[i] & ~known_bits[i + 1];
            if (can_set_to_1) {
                changed = true;
                a[i + 1] |= ~a[i] & can_set_to_1;
                known_bits[i + 1] |= can_set_to_1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            int can_set_to_0 = known_bits[i + 1] & ~known_bits[i];
            if (can_set_to_0) {
                changed = true;
                a[i] |= ~a[i + 1] & can_set_to_0;
                known_bits[i] |= can_set_to_0;
            }

            int can_set_to_1 = known_bits[i] & ~known_bits[i + 1];
            if (can_set_to_1) {
                changed = true;
                a[i + 1] |= ~a[i] & can_set_to_1;
                known_bits[i + 1] |= can_set_to_1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (known_bits[i] != ALL) {
            throw;
        }
    }

    sort(a, a + n);
    cout << "finish " << a[k - 1] << endl;
}