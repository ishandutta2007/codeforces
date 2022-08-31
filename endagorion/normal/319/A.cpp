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

const long long P = 1000000000 + 7;

long long deg(long long x) {
    if (x == 0) {
        return 1;
    }
    long long y = deg(x / 2);
    y = (y * y) % P;
    if (x % 2 == 1) {
        y = (y * 2) % P;
    }
    return y;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    string s;
    cin >> s;
    int N = s.size();
    long long ans = 0;
    reverse(all(s));
    for (int k = 0; k < N; ++k) {
        if (s[k] == '1') {
            ans = (ans + deg(N + k - 1)) % P;
        }
    }
    cout << ans << '\n';

	return 0;
}