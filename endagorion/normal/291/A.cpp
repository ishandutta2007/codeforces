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
    vector<int> a;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x > 0) {
            a.pb(x);
        }
    }
    sort(all(a));
    a.pb(1000000009);
    int eq = 1, c = 0;
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1]) {
            ++eq;
        } else {
            if (eq == 2) {
                ++c;
            } else {
                if (eq > 2) {
                    c = -1;
                    break;
                }
            }
            eq = 1;            
        }
    }

    cout << c << '\n';

    return 0;
}