#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 200 * 1000 + 100;

int n;
char str[maxn];
char tmp[maxn];
int b[maxn];

bool checkZero() {
    for (int i = 0; i <= 2 * n; i++) {
        if (b[i] < 0) {
            return false;
        }
    }

    return true;
}

bool tryTmp() {
    int hb = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (tmp[i] == '(') {
            hb++;
        } else {
            hb--;
        }
        if (hb < 0) {
            return false;
        }
    }

    return true;
}

void makeTmpReverse(int lb, int rb) {
    for (int i = 0; i < 2 * n; i++) {
        tmp[i] = str[i];
    }
    while (lb < rb) {
        swap(tmp[lb], tmp[rb]);
        lb++;
        rb--;
    }
}

bool checkOne(int& lb, int& rb) {
    lb = 0;
    while (b[lb] >= 0) {
        lb++;
    }
    rb = 2 * n;
    while (b[rb] >= 0) {
        rb--;
    }

    int hlb = 0;
    int lmax = 0;
    for (int i = 1; i <= lb; i++) {
        if (b[i] > lmax) {
            lmax = b[i];
            hlb = i;
        }
    }
    int hrb = 2 * n;
    lmax = 0;
    for (int i = rb; i <= 2 * n; i++) {
        if (b[i] > lmax) {
            lmax = b[i];
            hrb = i;
        }
    }

    makeTmpReverse(hlb, hrb - 1);
    lb = hlb + 1;
    rb = hrb;

    return tryTmp();
}

int findMax() {
    int best = 0;
    int p = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (b[i + 1] > best) {
            best = b[i + 1];
            p = i + 1;
        }
    }

    return p;
}

vector <pair <int, int> > solve() {
    b[0] = 0;
    for (int i = 0; i < 2 * n; i++) {
        b[i + 1] = b[i];
        if (str[i] == '(') {
            b[i + 1]++;            
        } else {
            b[i + 1]--;
        }
    }

    if (checkZero()) {
        return vector <pair <int, int> >();
    }
    int lb, rb;
    if (checkOne(lb, rb)) {
        vector <pair <int, int> > res;
        res.pb(mp(lb, rb));

        return res;
    }
    
    vector <pair <int, int> > res;
    int ps = findMax();

    res.pb(mp(1, ps));
    res.pb(mp(ps + 1, 2 * n));

    return res;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    scanf("%d", &tnum);
    for (int tc = 0; tc < tnum; tc++) {
        scanf("%d", &n);
        scanf("%s", str);

        vector <pair <int, int> > ans = solve();

        printf("%d\n", int(ans.size()));
        for (int i = 0; i < (int) ans.size(); i++) {
            printf("%d %d\n", ans[i].fs, ans[i].sc);
        }
    }

    return 0;
}