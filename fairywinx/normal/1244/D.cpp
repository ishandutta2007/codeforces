#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    long long n;
    long long ans = 1e17, loc_ans = 0;
    vector<long long> c;
    cin >> n;
    vector< vector<long long> > col(3, vector<long long> (n));
    for(long long i = 0; i < n; ++i) cin >> col[0][i];
    for(long long i = 0; i < n; ++i) cin >> col[1][i];
    for(long long i = 0; i < n; ++i) cin >> col[2][i];

    vector< vector<long long> > g(n, vector<long long> (0));
    long long a, b, f, nw;
    for(long long i = 1; i < n; ++i) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    for(long long i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            f = i;
            break;
        }
    }

    queue<long long> q;
    vector<bool> used(n);
    vector<long long> d(n);
    q.push(f);
    while(!q.empty()) {
        nw = q.front();
        q.pop();
        if (g[nw].size() > 2) {
            cout << -1;
            return 0;
        }
        used[nw] = true;
        for(long long i = 0; i < g[nw].size(); ++i) {
            if (!used[g[nw][i]]) {
                d[g[nw][i]] = d[nw] + 1;
                q.push(g[nw][i]);
            }
        }
    }

    for(long long i = 0; i < 3; ++i) {
        for(long long j = 0; j < 3; ++j) {
            loc_ans = 0;
            if (j == i) continue;
            long long co[3] = {i, j, 3 - i - j};
            for (long long u = 0; u < n; ++u) {
                loc_ans += col[co[d[u] % 3]][u];
                //cout << col[co[(d[u] + i) % 3]][j] << ' ' << co[(d[u] + i) % 3] << ' ' << co[(d[u] + i) % 3] << ' ' << u << endl;
            }
            //cout << loc_ans << endl;
            if (loc_ans < ans) {
                ans = loc_ans;
                loc_ans = 0;
                c.clear();
                c.push_back(i);
                c.push_back(j);
                c.push_back(3 - i - j);
            }
        }
    }



    cout << ans << endl;

    for(long long i = 0; i < n; ++i) {
        cout << c[d[i] % 3] + 1 << ' ' ;
    }
    cout << endl;
}