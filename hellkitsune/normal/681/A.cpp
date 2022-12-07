#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;
int a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    bool ok = false;
    REP(i, n) {
        cin >> s >> a >> b;
        if (a >= 2400 && b > a) {
            ok = true;
        }
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}