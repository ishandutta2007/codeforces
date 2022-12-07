#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;
set<string> se;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n) {
        cin >> s;
        if (se.count(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        se.insert(s);
    }
    return 0;
}