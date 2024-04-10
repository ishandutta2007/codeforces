#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,ans;
char p[100005],s[100005],t[100005];

int main()
{
    cin >> s >> t;
    n = strlen(s);
    for (int i = 0; i < n; ++i) ans += s[i] != t[i];
    if (ans % 2) cout << "impossible", exit(0);
    ans /= 2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) p[i] = s[i];
        else if (ans) ans--, p[i] = s[i];
        else p[i] = t[i];
    }
    cout << p;

    return 0;
}