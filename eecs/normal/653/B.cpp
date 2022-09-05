#include <bits/stdc++.h>
using namespace std;

int n, q, ans, tr[6][6];

int main() {
    cin >> n >> q;
    memset(tr, -1, sizeof(tr));
    while (q--) {
        string a, b;
        cin >> a >> b;
        tr[a[0] - 'a'][a[1] - 'a'] = b[0] - 'a';
    }
    string s;
    function<void(int)> dfs = [&](int cur) {
        if (cur == n) {
            string t = s;
            while (t.size() > 1) {
                int v = tr[t[0] - 'a'][t[1] - 'a'];
                if (!~v) break;
                t.erase(t.begin()), t.erase(t.begin());
                t.insert(t.begin(), v + 'a');
            }
            if (t.size() == 1 && t[0] == 'a') ans++;
            return;
        }
        for (char ch = 'a'; ch <= 'f'; ch++) {
            s.push_back(ch), dfs(cur + 1);
            s.pop_back();
        }
    };
    dfs(0), printf("%d\n", ans);
    return 0;
}