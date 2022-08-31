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

void getHappy(vector< long long > &happy, long long n, int d) {
    happy.push_back(n);
    if (d == 0) {
        return;
    }
    getHappy(happy, 10 * n + 4, d - 1);
    getHappy(happy, 10 * n + 7, d - 1);
}

long long happySum(long long n, vector< long long > &happy) {
    long long result = 0;
    for (size_t i = 1; i < happy.size() && happy[i - 1] < n; ++i) {
        result += happy[i] * (min(n, happy[i]) - happy[i - 1]);
    }
    return result;
}

int main() {
    vector< long long > happy;
    getHappy(happy, 0, 10);
    sort(happy.begin(), happy.end());
    long long l, r;
    cin >> l >> r;
    cout << happySum(r, happy) - happySum(l - 1, happy) << '\n';
    return 0;
}