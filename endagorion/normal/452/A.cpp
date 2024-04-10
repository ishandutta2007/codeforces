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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

bool match(const string &s, const string &t) {
    if (s.size() != t.size()) return false;
    forn(i, s.size()) {         
        if (s[i] != '.' && t[i] != '.' && s[i] != t[i]) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    vector<string> s;
    s.pb("vaporeon");
    s.pb("jolteon");
    s.pb("flareon");
    s.pb("espeon");
    s.pb("umbreon");
    s.pb("leafeon");
    s.pb("glaceon");
    s.pb("sylveon");

    int N;
    cin >> N;
    string t;
    cin >> t;
    forn(i, s.size()) {
        if (match(s[i], t)) cout << s[i] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}