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

int n;
string s, x, t;
map<string, int> ma;
int mac = 0;
int d[205] = {};

int getHash(string &s) {
    auto it = ma.find(s);
    if (it == ma.end()) {
        return ma[s] = mac++;
    } else {
        return it->second;
    }
}

void toLower(string &s) {
    for (char &c : s) if (c >= 'A' && c <= 'Z') {
        c -= 'A';
        c += 'a';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    s = "polycarp";
    d[getHash(s)] = 1;
    int ans = 1;
    REP(i, n) {
        cin >> s >> x >> t;
        toLower(s);
        toLower(t);
        int hs = getHash(s);
        int ht = getHash(t);
        d[hs] = d[ht] + 1;
        ans = max(ans, d[hs]);
    }
    cout << ans << endl;
    return 0;
}