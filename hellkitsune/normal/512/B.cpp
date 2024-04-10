#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <unordered_map>
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

unordered_map<int, int> ma;
int n;
int l[300], c[300];
vector<PII> lat;

inline int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

void upd(int pos, int val) {
    auto it = ma.find(pos);
    if (it == ma.end())
        ma[pos] = val;
    else
        it->second = min(it->second, val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> l[i];
    REP(i, n) cin >> c[i];
    REP(i, n) {
        upd(l[i], c[i]);
        for (auto it = ma.begin(); it != ma.end(); ++it)
            lat.pb(mp(gcd(it->first, l[i]), it->second + c[i]));
        REP(i, lat.size())
            upd(lat[i].first, lat[i].second);
        lat.clear();
    }
    if (ma.count(1))
        cout << ma[1] << endl;
    else
        cout << -1 << endl;
    return 0;
}