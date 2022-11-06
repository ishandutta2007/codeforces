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
    ios_base::sync_with_stdio(false);

    uint32_t n, k;
    cin >> n >> k;

    if (n > k * k - k) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    int base = 1;
    int run = 2;
    while (n > 0) {
        cout << base << ' ' << run << '\n';
        if (n > 1) {
            cout << run << ' ' << base << '\n';
            n -= 2;
        } else {
            n--;
        }

        if (run == k) {
            ++base;
            run = base + 1;
        } else {
            ++run;
        }
    }

    return 0;
}