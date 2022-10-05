#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool check(const string &s, const string &t) {
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (j < t.size() && s[i] == t[j]) ++j;
    }
    return j == t.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, p;
    cin >> s >> p;
    int n = (int)s.size();
    vector <int> del(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        del[i] = x;
    }
    vector <int> used(n);
    int l = 0;
    int r = n;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        string tmp = "";
        used.assign(n, 0);
        for (int i = 0; i < m; ++i) {
            used[del[i]] = 1;
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) tmp += s[i];
        }
        if (check(tmp, p)) l = m;
        else r = m;
    }
    cout << l << endl;
}