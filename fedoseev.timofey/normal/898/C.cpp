#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map <string, set <string>> phones;
    for (int i = 0; i < n; ++i) {
        string s; int x;
        cin >> s >> x;
        for (int i = 0; i < x; ++i) {
            string k;
            cin >> k;
            phones[s].insert(k);
        }
    }
    for (auto &p : phones) {
        set <string> to_del;
        for (auto &e : p.second) {
            for (auto &c : p.second) {
                if (e == c) continue;
                string s1 = e;
                string s2 = c;
                if (s1.size() > s2.size()) swap(s1, s2);
                bool fl = true;
                int len = s2.size() - s1.size();
                for (int i = 0; i < s1.size(); ++i) {
                    if (s1[i] != s2[i + len]) fl = false;
                }
                if (fl) to_del.insert(s1);
            }
        }
        for (auto &e : to_del) p.second.erase(e);
    }
    cout << phones.size() << endl;
    for (auto &p : phones) {
        cout << p.first << " ";
        cout << p.second.size() << " ";
        for (auto &e : p.second) cout << e << " ";
        cout << endl;
    }
}