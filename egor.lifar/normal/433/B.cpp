#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n, m;
int v[100000];
long long d[100000], s[100000];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        d[i] = v[i] + (i > 0 ? d[i - 1]: 0);
    }
    sort(v, v + n);
    for (int i = 0; i < n; i++) {
        s[i] = v[i] + (i > 0 ? s[i - 1]: 0);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        l--;
        r--;
        if (type == 1) {
            cout << d[r] - (l > 0 ? d[l - 1]: 0) << endl;
        } else {
            cout << s[r] - (l > 0 ? s[l - 1]: 0) << endl;
        }
    }
    return 0;
}