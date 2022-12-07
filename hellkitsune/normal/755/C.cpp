#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> v;

int main() {
    scanf("%d", &n);
    int ans = 0;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        if (x == i + 1) {
            ++ans;
        } else {
            v.pb(x);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ans += int(v.size()) / 2;
    cout << ans << endl;
    return 0;
}