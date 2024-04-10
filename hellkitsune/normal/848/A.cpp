#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int k;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> k;
    for (char c = 'a'; c <= 'z'; ++c) {
        s.pb(c);
        for (int i = 1; i <= k; ++i) {
            k -= i;
            s.pb(c);
        }
    }
    cout << s << endl;
    return 0;
}