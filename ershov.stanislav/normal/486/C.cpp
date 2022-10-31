#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 111111;

int n, p, ans, mn = N, mx;
char s[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> p;
    cin >> s;
    if (p>n/2) p = n+1-p;
    p--;
    for (int i = 0; i < n/2; i ++) {
        int ch = min(abs(s[n-1-i] - s[i]), abs(26 - abs(s[n-1-i] - s[i])));
        ans += ch;
        if (ch >= 1) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if (ans) {
        ans += min(abs(p-mn)+abs(mn-mx), abs(p-mx)+abs(mn-mx));
    }
    cout << ans << endl;
    return 0;
}