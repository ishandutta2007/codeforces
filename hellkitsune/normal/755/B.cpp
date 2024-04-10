#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char buf[1005];
set<string> a;
int p = 0, q = 0, both = 0;

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%s", buf);
        a.insert(string(buf));
    }
    p = n;
    forn(i, m) {
        scanf("%s", buf);
        string s = string(buf);
        if (a.count(s)) {
            --p;
            ++both;
        } else {
            ++q;
        }
    }
    while (true) {
        if (p == 0 && both == 0) {
            cout << "NO" << endl;
            break;
        }
        if (both) --both;
        else --p;
        if (q == 0 && both == 0) {
            cout << "YES" << endl;
            break;
        }
        if (both) --both;
        else --q;
    }
    return 0;
}