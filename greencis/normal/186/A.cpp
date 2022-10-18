#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s, t;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s >> t;
    if (s.size() != t.size()) {
        cout << "NO";
    } else {
        int x = 0;
        for (int i = 0; s[i]; ++i)
            x += s[i] != t[i];
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (x == 2 && s == t)
            cout << "YES";
        else
            cout << "NO";
    }

    return 0;
}