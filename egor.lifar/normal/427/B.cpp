#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>


using namespace std;


int n, c, t;
int a[200001];
multiset<int> s;
int ans = 0;

int main() {
    cin >> n >> t >> c;
    if (c == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < c; i++) {
        s.insert(a[i]);
    }
    for (int i = c - 1; i < n; i++) {
        if (*s.rbegin() <= t) {
            ans++;
        }
        s.erase(s.find(a[i - c + 1]));
        s.insert(a[i + 1]);
    }
    cout << ans << endl;
    return 0;
}