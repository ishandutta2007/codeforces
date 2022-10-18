#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

char s1[15],s2[15];
int b, q;

int main()
{
    cin >> s1 >> s2;
    for (int i = 0; s1[i]; ++i) {
        if (s1[i] == '+') ++b;
        else if (s1[i] == '-') --b;
    }
    for (int i = 0; s2[i]; ++i) {
        if (s2[i] == '+') --b;
        else if (s2[i] == '-') ++b;
        else if (s2[i] == '?') ++q;
    }
    b = abs(b);
    if ((q - b) % 2) { cout << 0; return 0; }
    b = (q + b) / 2;
    ld ans = 1;
    for (int i = 2; i <= q; ++i)
        ans *= ld(i);
    for (int i = 2; i <= b; ++i)
        ans /= ld(i);
    for (int i = 2; i <= q - b; ++i)
        ans /= ld(i);
    ans /= ld(1 << q);
    if (b > q) ans = 0;
    cout.precision(17);
    cout << fixed << ans;

    return 0;
}