#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        bool fl = false;
        for (int n = 1; n <= 1e5; ++n) {
            ll need = (ll)n * n - x;
            if (need <= 0) continue;
            int l = 0;
            int r = (int)1e9;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (ll(n / m) * (n / m) <= need) r = m;
                else l = m;
            }
            if ((ll)(n / r) * (n / r) == need) {
                cout << n << " " << r << endl;
                fl = true;
                break;
            }
        }
        if (!fl) {
            cout << -1 << endl;
        }
    }
}