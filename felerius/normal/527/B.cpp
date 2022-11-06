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

    size_t l;
    string s, t;
    cin >> l;
    cin >> s >> t;

    array<int, 26 * 26> p;
    fill(begin(p), end(p), -1);

    int ham = 0;
    for (size_t i = 0; i < l; ++i) {
        if (s[i] != t[i]) {
            ham++;
            p[(s[i] - 'a') * 26 + (t[i] - 'a')] = i;
        }
    }

    for (size_t i = 0; i < 26; ++i) {
        for (size_t j = i + 1; j < 26; ++j) {
            if (p[i * 26 + j] != -1 && p[j * 26 + i] != -1) {
                cout << (ham - 2) << '\n';
                cout << (p[i * 26 + j] + 1) << ' ' << (p[j * 26 + i] + 1) << '\n';
                return 0;
            }
        }
    }

    for (size_t i = 0; i < 26; ++i) {
        int idx1 = -1;
        for (size_t j = 0; j < 26; ++j) {
            if (p[i * 26 + j] != -1) {
                idx1 = p[i * 26 + j];
                break;
            }
        }

        if (idx1 == -1) {
            continue;
        }

        int idx2 = -1;
        for (size_t j = 0; j < 26; ++j) {
            if (p[j * 26 + i] != -1) {
                idx2 = p[j * 26 + i];
                break;
            }
        }

        if (idx2 != -1) {
            cout << (ham - 1) << '\n' << (idx1 + 1) << ' ' << (idx2 + 1) << '\n';
            return 0;
        }
    }

    cout << ham << "\n-1 -1\n";

    return 0;
}