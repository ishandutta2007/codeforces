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


int n, k;
string s;
int da[100001], db[100001];


int getsuma(int l, int r) {
    return da[r] - (l > 0 ? da[l - 1]: 0);
}


int getsumb(int l, int r) {
    return db[r] - (l > 0 ? db[l - 1]: 0);
}


bool gooda(int l, int r) {
    return getsumb(l, r) <= k;
}

bool goodb(int l, int r) {
    return getsuma(l, r) <= k;
}


int main() {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        da[i] += (s[i] == 'a');
        db[i] += (s[i] == 'b');
        if (i != 0) {
            da[i] += da[i - 1];
            db[i] += db[i - 1];
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (gooda(i, i)) {
            int l = i;
            int r = n - 1;
            while (l != r) {
                int m = (l + r + 1) / 2;
                if (gooda(i, m)) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
            ans = max(ans, l - i + 1);
        }
        if (goodb(i, i)) {
            int l = i;
            int r = n - 1;
            while (l != r) {
                int m = (l + r + 1) / 2;
                if (goodb(i, m)) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
            ans = max(ans, l - i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}