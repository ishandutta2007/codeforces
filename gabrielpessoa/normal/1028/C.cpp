#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int ms = 3e5+5;

int bit[ms], n;

void update(int v, int idx) {
    while(idx <= n) {
        bit[idx] += v;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int r = 0;
    while(idx > 0) {
        r += bit[idx];
        idx -= idx & -idx;
    }
    return r;
}

vector<int> ans;
vector<int> ans2;
ii sweep[ms];
ii sweep2[ms];

void solve(ii *sweep, int n, vector<int> &ans) {
    sort(sweep, sweep + n + n);
    int sum = 0;
    for(int i = 0; i < n + n; i++) {
        if(sweep[i].second >= n) {
            sum--;            
            if(sum >= n-2) {
                ans.push_back(sweep[i].first);
            }
        }
        else sum++;
    }
}

pair<ii, ii> ret[ms];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ret[i] = {{x1, y1}, {x2, y2}};
        sweep[i] = {x1, i};
        sweep[i+n] = {x2, i + n};
        sweep2[i] = {y1, i};
        sweep2[i+n] = {y2, i+n};
    }
    solve(sweep, n, ans);
    solve(sweep2, n, ans2);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans2.size(); j++) {
            int qnt = 0;
            for(int k = 0; k < n; k++) {
                if(ans[i] >= ret[k].first.first && ans[i] <= ret[k].second.first && ans2[j] >= ret[k].first.second && ans2[j] <= ret[k].second.second) {
                    qnt++;
                }
            }
            if(qnt >= n - 1) {
                cout << ans[i] << ' ' << ans2[j] << "\n";
                return 0;
            }
        }
    }
}