#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int n;
char s[300105];
ll ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] % 4 == 0) ++ans;
        if (i && ((s[i-1] - 48) * 10 + s[i] - 48) % 4 == 0) ans += i;
    }
    cout << ans;

    return 0;
}