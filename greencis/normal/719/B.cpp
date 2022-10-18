#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s;
int n;

int main()
{
    cin >> n >> s;
    int ans = 2e9;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'r' && i % 2 != 0) ++c1;
        if (s[i] == 'b' && i % 2 == 0) ++c2;
    }
    ans = min(ans, max(c1, c2));
    c1 = c2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'r' && i % 2 == 0) ++c1;
        if (s[i] == 'b' && i % 2 != 0) ++c2;
    }
    ans = min(ans, max(c1, c2));
    cout << ans;

    return 0;
}