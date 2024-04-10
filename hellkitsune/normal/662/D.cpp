#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define mp make_pair
#define pb push_back
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL x;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) {
        string s;
        cin >> s;
        s.erase(0, 4);
        int len = (int)s.length();
        istringstream iss(s);
        iss >> x;
        LL ans = 1988;
        for (LL dig = 1; len > 0; dig *= 10, --len) {
            ++ans;
            if (ans % (dig * 10) != x % (dig * 10)) {
                if (ans % (dig * 10) < x % (dig * 10)) {
                    ans -= ans % (dig * 10);
                    ans += x % (dig * 10);
                } else {
                    ans -= ans % (dig * 10);
                    ans += dig * 10;
                    ans += x % (dig * 10);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}