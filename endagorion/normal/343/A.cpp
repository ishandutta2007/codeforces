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


long long ans(long long a, long long b) {
    if (b == 0) {
        return 0;
    }
    return a / b + ans(b, a % b);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    long long a, b;
    cin >> a >> b;
    cout << ans(a, b) << '\n';

    return 0;
}