#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
string ans;
string s;

int main()
{
    cin >> n >> s;
    ans = "z";
    s += s;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < n; ++j)
            ans = min(ans, s.substr(j, n));
        for (int j = 0; j < n + n; ++j) {
            int dig = s[j] - 48;
            ++dig;
            dig %= 10;
            s[j] = dig + 48;
        }
    }
    cout << ans;

    return 0;
}