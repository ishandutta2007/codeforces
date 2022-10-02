#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;


int n, v;
set<int> a;
map<int, int> l;
map<int, int> r;


int main() {
    cin >> n >> v;
    a.insert(v);
    for (int i = 0; i < n - 1; i++) {
        cin >> v;
        auto it = a.upper_bound(v);
        int ans = 0;
        if (it != a.end() && l.count(*it) == 0) {
            int p = *it;
            l[p] = v;
            ans = p;
        } else {
            it--;
            int p = *it;
            r[p] = v;
            ans = p;
        }
        a.insert(v);
        cout << ans;
        if (i == n - 2) {
            cout << '\n';
        } else {
            cout << ' ';
        }
    }
    return 0;
}