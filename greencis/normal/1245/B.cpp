#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, r, p, s;
        string str;
        cin >> n >> r >> p >> s >> str;
        string ans(n, ' ');
        map<char, vector<int>> cnt;
        for (int i = 0; str[i]; ++i) {
            cnt[str[i]].push_back(i);
        }
        int wins = min((int)cnt['R'].size(), p) + min((int)cnt['P'].size(), s) + min((int)cnt['S'].size(), r);
        if (wins < (n + 1) / 2) {
            cout << "NO" << endl;
            continue;
        }

        for (int i = 0; i < cnt['R'].size() && p > 0; ++i) {
            ans[cnt['R'][i]] = 'P';
            --p;
        }
        for (int i = 0; i < cnt['P'].size() && s > 0; ++i) {
            ans[cnt['P'][i]] = 'S';
            --s;
        }
        for (int i = 0; i < cnt['S'].size() && r > 0; ++i) {
            ans[cnt['S'][i]] = 'R';
            --r;
        }
        for (int i = 0; ans[i]; ++i) {
            if (ans[i] == ' ') {
                if (r > 0) ans[i] = 'R', --r;
                else if (p > 0) ans[i] = 'P', --p;
                else if (s > 0) ans[i] = 'S', --s;
            }
        }
        cout << "YES" << endl;
        cout << ans << endl;
    }
}