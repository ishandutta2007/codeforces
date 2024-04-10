#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

using ll = long long;
#define debug(x) cerr << #x << ": <" << x << ">\n"
#define sz(x) (int)x.size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    ioThings();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<pair<int, int>, vector<int>> pos;
        pair<int, int> curPos = {0, 0};
        pos[curPos] = {0};
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L')
                curPos.fi--;
            else if (s[i] == 'R')
                curPos.fi++;
            else if (s[i] == 'D')
                curPos.se--;
            else
                curPos.se++;
            pos[curPos].pb(i + 1);
        }
        int x = -1, y;
        for (auto& i : pos) {
            int size = sz(i.se);
            if (size < 2)
                continue;
            if (x == -1)
                x = i.se[0], y = i.se[1];
            for (int j = 1; j < size; j++) {
                if (i.se[j] - i.se[j - 1] < y - x)
                    x = i.se[j - 1], y = i.se[j];
            }
        }
        if (x == -1)
            cout << "-1\n";
        else
            cout << x + 1 << ' ' << y << '\n';
    }

    return 0;
}