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

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long inter(long long a, long long b, long long c, long long d) {
    return max(0, min(b, d) - max(a, c) + 1);
}

void fill_happy(vector< long long > &happy, long long q, int left) {
    if (left == 0) {
        return;
    }
    happy.push_back(q);
    fill_happy(happy, q * 10 + 4, left - 1);
    fill_happy(happy, q * 10 + 7, left - 1);
}

int main() {
    long long pl, pr, vl, vr;
    int k;
    cin >> pl >> pr >> vl >> vr >> k;
    vector< long long > happy;
    fill_happy(happy, 0, 10);
    sort(happy.begin(), happy.end());
    happy.push_back(1000000001);
    long long cases = 0;
    for (size_t i = 0; i + k + 1 < happy.size(); ++i) {
        long long pr1 = inter(happy[i] + 1, happy[i + 1], pl, pr) * inter(happy[i + k], happy[i + k + 1] - 1, vl, vr);
        long long pr2 = inter(happy[i] + 1, happy[i + 1], vl, vr) * inter(happy[i + k], happy[i + k + 1] - 1, pl, pr);
        cases += pr1 + pr2;
        if (k == 1 && pr1 > 0 && pr2 > 0) {
            --cases;
        }
    }
    printf("%.12lf\n", (long double)1.0 * cases / ((pr - pl + 1) * (vr - vl + 1)));
    return 0;
}