#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <queue>
#include <cmath>
#include <algorithm>
 
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        a += (s[i] == 'a');
        b += (s[i] == 'b');
        c += (s[i] == 'c');
    }

    if (a == 0 || b == 0 || c == 0) {
        cout << "NO\n";
        return 0;
    }

    if (c != a && c != b) {
        cout << "NO\n";     
        return 0;
    }

    int lasta = -1, lastb = -1, lastc = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') lasta = max(lasta, i);
        if (s[i] == 'b') lastb = max(lastb, i);
        if (s[i] == 'c') lastc = max(lastc, i);
    }                        

    if (!(lasta < lastb && lastb < lastc)) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i <= lasta; ++i) {
        if (s[i] != 'a') {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = lasta + 1; i <= lastb; ++i) {
        if (s[i] != 'b') {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = lastb + 1; i <= lastc; ++i) {
        if (s[i] != 'c') {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}