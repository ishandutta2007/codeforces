#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

LL a[2], b[2], aa[2], bb[2];
LL rem[2];
int two[2] = {}, three[2] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a[0] >> b[0] >> a[1] >> b[1];
    REP(i, 2) aa[i] = a[i], bb[i] = b[i];
    REP(i, 2) {
        rem[i] = 1;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            ++two[i];
        }
        while (b[i] % 2 == 0) {
            b[i] /= 2;
            ++two[i];
        }
        while (a[i] % 3 == 0) {
            a[i] /= 3;
            ++three[i];
        }
        while (b[i] % 3 == 0) {
            b[i] /= 3;
            ++three[i];
        }
        rem[i] = a[i] * b[i];
    }
    if (rem[0] != rem[1]) {
        cout << "-1\n";
        return 0;
    }
    REP(i, 2) a[i] = aa[i], b[i] = bb[i];
    int ans = 0;
    REP(i, 2) {
        int j = i ^ 1;
        while (three[i] < three[j]) {
            --three[j];
            ++two[j];
            if (a[j] % 3 == 0) a[j] /= 3, a[j] *= 2;
            else b[j] /= 3, b[j] *= 2;
            ++ans;
        }
    }
    REP(i, 2) {
        int j = i ^ 1;
        while (two[i] < two[j]) {
            --two[j];
            if (a[j] % 2 == 0) a[j] /= 2;
            else b[j] /= 2;
            ++ans;
        }
    }
    cout << ans << '\n';
    cout << a[0] << ' ' << b[0] << '\n';
    cout << a[1] << ' ' << b[1] << '\n';
    return 0;
}