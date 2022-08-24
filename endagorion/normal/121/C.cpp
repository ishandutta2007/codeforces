#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

long long fact(long long n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

void getHappy(vector< long long > &happy, long long n, int d) {
    happy.push_back(n);
    if (d == 0) {
        return;
    }
    getHappy(happy, 10 * n + 4, d - 1);
    getHappy(happy, 10 * n + 7, d - 1);
}

bool isHappy(long long n) {
    if (n == 0) {
        return true;
    }
    return (n % 10 == 4 || n % 10 == 7) && isHappy(n / 10);
}

int main() {
    long long n, k;
    cin >> n >> k;
    --k;
    vector< int > numbers;
    int d = min(n, (long long)13);
    vector< bool > used(d, false);
    if (n < 13 && k >= fact(n)) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < d; ++i) {
        int cur = 0;
        while (used[cur]) {
            ++cur;
        }
        while (k >= fact(d - i - 1)) {
            k -= fact(d - i - 1);
            ++cur;
            while (used[cur]) {
                ++cur;
            }
        }
        numbers.push_back(cur);
        used[cur] = true;
    }
    vector< long long > happy;  
    getHappy(happy, 0, 10);
    sort(happy.begin(), happy.end());
    int ans = 0;
    for (int i = 1; i < happy.size() && happy[i] <= n; ++i) {
        if (happy[i] <= n - d) {
            ++ans;
        } else {
            long long q = n - d + 1 + numbers[happy[i] - (n - d + 1)];
            if (isHappy(q)) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}