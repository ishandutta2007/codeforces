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


int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    long long L, R;
    cin >> L >> R;
    long long D = 1;
    while (D <= R) {
        D *= 10;
    }
    long long x = max(L, min(R, D / 2));
    cout << x * (D - x - 1) << '\n';

	return 0;
}