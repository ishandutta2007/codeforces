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

    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    long long l = 0, r = 1e10;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        long long s = 0;
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (a[i] > m) {
                ok = false;
                break;
            }
            s += m - a[i];
        }
        if (ok && s >= m) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';


	return 0;
}