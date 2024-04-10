#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    int l = 1;
    int r = n;
    for (int i = 0; i < m; i++) {
        string s, s1, s2, s3;
        int a;
        cin >> s >> s1 >> s2 >> s3 >> a;
        if (s2 == "right") {
            l = max(a + 1, l);
        } else {
            r = min(r, a - 1);
        }
    }
    if (l > r) {
        cout << -1 << endl;
    } else {
        cout << (r - l + 1) << endl;
    }
    return 0;
}