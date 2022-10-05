#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool flag = false;
    set <char> can_be;
    set <char> cannot_be;
    bool fl = true;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        string s;
        cin >> s;
        if (i == n - 1) continue;
        if (flag && c != '.') ++ans;
        if (c == '.' || c == '?') {
            for (auto d : s) {
                cannot_be.insert(d);
            }
        }
        set <char> tmp;
        bool t = false;
        if (c == '!') {
            t = true;
            for (auto d : s) {
                if (fl) {
                    can_be.insert(d);
                    tmp.insert(d);
                }
                else {
                    if (!can_be.count(d)) {
                        cannot_be.insert(d);
                    }
                    else {
                        tmp.insert(d);
                    }
                }
            }
            fl = false;
        }
        if (t) {
            for (auto d : can_be) {
                if (!tmp.count(d)) {
                    cannot_be.insert(d);
                }
            }
        }
        for (auto d : cannot_be) {
            can_be.erase(d);
        }
        if (can_be.size() == 1 || cannot_be.size() == 25) {
            flag = true;
        }
    }
    cout << ans << endl;
}