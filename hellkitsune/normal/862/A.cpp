#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, x;
int have[105];

int main() {
    cin >> n >> x;
    forn(i, n) {
        int val;
        cin >> val;
        ++have[val];
    }
    int ans = 0;
    forn(i, x) if (have[i] == 0) {
        ans += 1;
    }
    ans += have[x];
    cout << ans << endl;
    return 0;
}