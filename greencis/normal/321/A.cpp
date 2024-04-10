#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n,x[105],y[105],a,b;
char s[105];

int main()
{
    cin >> a >> b >> s+1;
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'U') x[i] = x[i-1], y[i] = y[i-1] + 1;
        else if (s[i] == 'D') x[i] = x[i-1], y[i] = y[i-1] - 1;
        else if (s[i] == 'L') x[i] = x[i-1] - 1, y[i] = y[i-1];
        else if (s[i] == 'R') x[i] = x[i-1] + 1, y[i] = y[i-1];
    }

    bool good = false;

    for (int i = 0; i <= n; ++i) {
        if (x[n]) {
            if (y[n]) {
                int kx = (a - x[i]) / x[n];
                int ky = (b - y[i]) / y[n];
                if ((a - x[i]) % x[n] == 0 && kx >= 0 && (b - y[i]) % y[n] == 0 && ky >= 0 && kx == ky) good = true;
            } else {
                int kx = (a - x[i]) / x[n];
                if ((a - x[i]) % x[n] == 0 && kx >= 0 && y[i] == b) good = true;
            }
        } else {
            if (y[n]) {
                int ky = (b - y[i]) / y[n];
                if ((b - y[i]) % y[n] == 0 && ky >= 0 && x[i] == a) good = true;
            } else {
                if (x[i] == a && y[i] == b) good = true;
            }
        }
    }

    if (good) cout << "Yes";
    else cout << "No";

    return 0;
}