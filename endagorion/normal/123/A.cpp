#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

bool prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int comp = s.length() - 1;
    for (int i = 2; i <= s.length(); ++i) {
        if (2 * i > s.length() && prime(i)) {
            --comp;
        }
    }
    vector< int > letters(26, 0);
    for (size_t i = 0; i < s.length(); ++i) {
        ++letters[s[i] - 'a'];
    }

    bool ok = false;
    int let;
    for (size_t i = 0; i < 26; ++i) {
        if (letters[i] >= comp) {
            ok = true;
            let = i;
            break;
        }
    }
    int cur = 0;
    if (!ok) {
        cout << "NO\n";
        return 0;
    }
    letters[let] -= comp;

    cout << "YES\n";
    string t = "";
    for (int i = 1; i <= s.length(); ++i) {
        if (i == 1 || (2 * i > s.length() && prime(i))) {
            while (letters[cur] == 0) {
                ++cur;
            }
            t += (char)('a' + cur);
            --letters[cur];
        } else {
            t += (char)('a' + let);
        }
    }
    cout << t << '\n';

    return 0;
}