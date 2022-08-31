#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

long long fact(long long x) {
    long long res = 1;
    for (long long i = 2; i <= x; ++i) {
        res *= i;
    }
    return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    string s;
    cin >> s;
    vector<bool> pres(10);
    int lCount = 0;
    int zCount = 0;
    long long p = 1;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            if (i == 0) {
                p = 9;
            } else {
                ++zCount;
            }
        }
        if (s[i] >= 'A' && s[i] <= 'J') {
            if (!pres[s[i] - 'A']) {
                ++lCount;
            }
            pres[s[i] - 'A'] = true;
        }
    }
    long long ans = fact(10) / fact(10 - lCount);
    if (s[0] >= 'A' && s[0] <= 'Z') {
        ans -= fact(9) / fact(10 - lCount);
    }
    cout << p * ans;
    for (int z = 0; z < zCount; ++z) {
        cout << '0';
    }
    cout << '\n';

	return 0;
}