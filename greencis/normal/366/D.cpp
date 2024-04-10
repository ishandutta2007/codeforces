#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[6005], b[6005], l[6005], r[6005];
vector<int> g[3005];
int ans = 0;

bool check(int L, int R) {
    vector<char> used(n + 1);
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int curv = q.front();
        q.pop();
        if (used[curv])
            continue;
        if (curv == n)
            return true;
        used[curv] = 1;
        for (size_t i = 0; i < g[curv].size(); ++i) {
            int to = g[curv][i];
            if (l[to] <= L && R <= r[to])
                q.push(b[to]);
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i + i] >> b[i + i] >> l[i + i] >> r[i + i];
        a[i + i + 1] = b[i + i];
        b[i + i + 1] = a[i + i];
        l[i + i + 1] = l[i + i];
        r[i + i + 1] = r[i + i];
        g[a[i + i]].push_back(i + i);
        g[b[i + i]].push_back(i + i + 1);
    }

    for (int i = 0; i < m; ++i) {
        int L = l[i + i], R = r[i + i];
        while (L < R) {
            int mid = (L + R + 1) >> 1;
            if (check(l[i + i], mid))
                L = mid;
            else
                R = mid - 1;
        }
        if (L > l[i + i] || check(L, L))
            ans = max(ans, L - l[i + i] + 1);
    }

    if (ans)
        cout << ans << endl;
    else
        cout << "Nice work, Dima!" << endl;

    return 0;
}