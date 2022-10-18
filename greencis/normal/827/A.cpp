#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, k, x;
string s[100105], ans;
vector<pii> v;

int main()
{
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> k;
        while (k--) {
            cin >> x;
            n = max(n, x + (int)s[i].size() - 1);
            v.push_back(make_pair(x - 1, i));
        }
    }
    for (int i = n; i--; )
        ans += 'a';
    sort(v.begin(), v.end());
    int last = -1;
    for (pii p : v) {
        int rg = p.first + (int)s[p.second].size() - 1;
        if (rg > last) {
            for (int i = max(last + 1, p.first); i <= rg; ++i)
                ans[i] = s[p.second][i - p.first];
            last = max(last, rg);
        }
    }
    cout << ans;

    return 0;
}