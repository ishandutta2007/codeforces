#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    size_t zero = n;
    size_t one = n;
    vector<size_t> zero_before(n);
    vector<size_t> one_before(n);
    vector<size_t> zero_after(n);
    vector<size_t> one_after(n);

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0') {
            zero = i;
        } else {
            one = i;
        }
        zero_before[i] = zero;
        one_before[i] = one;
    }

    zero = one = n;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            zero = i;
        } else {
            one = i;
        }
        zero_after[i] = zero;
        one_after[i] = one;
    }

    if (zero_after[0] == n || one_after[0] == n) {
        cout << "tokitsukaze\n";
        return 0;
    }

    if (zero_before[n - 1] - zero_after[0] + 1 <= k || one_before[n - 1] - one_after[0] + 1 <= k) {
        cout << "tokitsukaze\n";
        return 0;
    }

    for (size_t i = 0; i < n - k; ++i) {
        size_t first_zero, last_zero, first_one, last_one;
        if (i > 0 && zero_after[0] < i) {
            first_zero = zero_after[0];
        } else {
            first_zero = zero_after[i + k];
        }

        if (i > 0 && one_after[0] < i) {
            first_one = one_after[0];
        } else {
            first_one = one_after[i + k];
        }

        if (i + k < n && zero_before[n - 1] >= i + k) {
            last_zero = zero_before[n - 1];
        } else {
            last_zero = zero_before[i - 1];
        }

        if (i + k < n && one_before[n - 1] >= i + k) {
            last_one = one_before[n - 1];
        } else {
            last_one = one_before[i - 1];
        }

        if (last_zero - first_zero + 1 > k || last_one - first_one + 1 > k) {
            cout << "once again\n";
            return 0;
        }
    }

    cout << "quailty\n";

    return 0;
}