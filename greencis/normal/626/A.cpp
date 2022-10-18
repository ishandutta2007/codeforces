#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

string s;
int n, cnt, l, r, u, d;

int main()
{
    cin >> n >> s;
    for (int i = 0; i < s.size(); ++i) {
        l = r = u = d = 0;
        for (int j = i; j < s.size(); ++j) {
            if (s[j] == 'L') ++l;
            if (s[j] == 'R') ++r;
            if (s[j] == 'U') ++u;
            if (s[j] == 'D') ++d;
            if (l == r && u == d) ++cnt;
        }
    }
    cout << cnt;

    return 0;
}