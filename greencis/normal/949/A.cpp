#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
string s;
set<int> pos[2];
vector<vector<int>> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i)
        pos[s[i] - '0'].insert(i);
    while (pos[0].size()) {
        vector<int> v;
        int curpos = *pos[0].begin();
        v.push_back(curpos);
        pos[0].erase(pos[0].begin());
        while (true) {
            auto it1 = pos[1].lower_bound(curpos + 1);
            if (it1 == pos[1].end())
                break;
            auto it0 = pos[0].lower_bound(*it1 + 1);
            if (it0 == pos[0].end())
                break;
            v.push_back(*it1);
            pos[1].erase(it1);
            v.push_back(*it0);
            curpos = *it0;
            pos[0].erase(it0);
        }
        ans.push_back(v);
    }
    if (pos[0].size() || pos[1].size()) {
        cout << -1;
        return 0;
    }
    cout << ans.size() << "\n";
    for (const vector<int>& v : ans) {
        cout << v.size();
        for (const int& x : v)
            cout << " " << x + 1;
        cout << "\n";
    }
}