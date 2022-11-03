#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*

*/

void solve() {

    string s;
    cin >> s;

    int n = s.length();

    int c0 = 0, c1 = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == '0')
            c0++;
        else
            c1++;

    int cnt = c0 - c1;

    if(cnt <= 0) {
        cout << -1;
        return;
    }

    vector<vector<int>> ans(cnt);
    queue<int> q0, q1;
    for(int i = 0; i < cnt; i++)
        q1.push(i);

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            if(q1.empty()) {
                cout << -1;
                return;
            }

            int j = q1.front();
            q1.pop();

            ans[j].push_back(i);
            q0.push(j);
        } else {
            if(q0.empty()) {
                cout << -1;
                return;
            }

            int j = q0.front();
            q0.pop();

            ans[j].push_back(i);
            q1.push(j);
        }
    }

    if(!q1.empty()) {
        cout << -1;
        return;
    }

    cout << cnt << endl;
    for(int i = 0; i < cnt; i++) {
        cout << ans[i].size() << ' ';
        for(auto x : ans[i])
            cout << x + 1 << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}