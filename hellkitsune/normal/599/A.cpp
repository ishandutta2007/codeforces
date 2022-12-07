#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a, b, c;

int main() {
    cin >> a >> b >> c;
    int ans = min(2 * (a + b), a + b + c);
    ans = min(ans, 2 * (a + c));
    ans = min(ans, 2 * (b + c));
    cout << ans << endl;
    return 0;
}