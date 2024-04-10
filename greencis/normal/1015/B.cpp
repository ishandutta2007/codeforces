#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
string s, t;
set<int> ps[256], pt[256];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> s >> t;
    for (int i = 0; s[i]; ++i) {
        ps[s[i]].insert(i);
        pt[t[i]].insert(i);
    }
    for (int i = 256; i--; ) {
        if (ps[i].size() != pt[i].size()) {
            cout << "-1";
            return 0;
        }
    }
    for (int i = 0; i + 1 < (int) s.size(); ++i) {
        while (s[i] != t[i]) {
            int idx = *ps[t[i]].begin();
            ps[s[idx]].erase(idx);
            ps[s[idx - 1]].erase(idx - 1);
            swap(s[idx], s[idx - 1]);
            ans.push_back(idx - 1);
            ps[s[idx]].insert(idx);
            ps[s[idx - 1]].insert(idx - 1);
        }
        pt[t[i]].erase(i);
        ps[s[i]].erase(i);
    }
    cout << ans.size() << endl;
    for (int x : ans)
        cout << x + 1 << " ";
}