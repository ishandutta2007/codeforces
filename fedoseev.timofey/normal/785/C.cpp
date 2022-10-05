#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    if (m >= n) {
        cout << n << endl;
    }
    else {
        long long left = 0;
        long long right = 2e9;
        n -= m;
        while (right - left > 1) {
            long long mid = (left + right) >> 1;
            if (mid * (mid + 1) / 2 >= n) right = mid;
            else left = mid;
        }
        cout << left + m + 1 << endl;
    }
}