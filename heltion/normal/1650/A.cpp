#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    for (cin >> t; t; t -= 1) {
        string s, c;
        cin >> s >> c;
        int ok = 0;
        if (s.size() & 1)
            for (int i = 0; i < s.size(); i += 2)
                if (s[i] == c[0])
                    ok = 1;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}