#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s, t;
char lookup[256];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s >> t;
    for (int i = 0; s[i]; ++i)
        lookup[s[i]] = t[i];
    cin >> s;
    for (int i = 0; s[i]; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = lookup[s[i] + 32] - 32;
        } else if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = lookup[s[i]];
    }
    cout << s;

    return 0;
}