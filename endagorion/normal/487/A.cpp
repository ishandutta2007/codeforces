#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

bool win(int myHp, int myAtk, int myDef, int tHp, int tAtk, int tDef) {
    if (myDef >= tAtk && tDef >= myAtk) return false;
    while (myHp > 0 && tHp > 0) {
        myHp -= max(0, tAtk - myDef);
        tHp -= max(0, myAtk - tDef);
    }
    return myHp > 0 && tHp <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int myHp, myAtk, myDef, tHp, tAtk, tDef;
    int cHp, cAtk, cDef;

    cin >> myHp >> myAtk >> myDef >> tHp >> tAtk >> tDef >> cHp >> cAtk >> cDef;
    int ans = 1e9;
    forn(addAtk, 201) forn(addDef, 201) {
        int l = -1, r = 10001;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (win(myHp + m, myAtk + addAtk, myDef + addDef, tHp, tAtk, tDef)) r = m;
            else l = m;
        }
        int res = cHp * r + cAtk * addAtk + cDef * addDef;
        if (win(myHp + r, myAtk + addAtk, myDef + addDef, tHp, tAtk, tDef) && res < ans) ans = res;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}