#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;

int d[MAXN];

bool comp(int a, int b) {
    return d[a] > d[b];
}

bool dl[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i < MAXN; ++i) {
        for (int j = i * 2; j < MAXN; j += i) {
            ++d[j];
        }
    }

    int have = 0;
    for (int i = 1; i <= n; ++i) {
        have += d[i];
    }

    if (have < k) {
        cout << "No\n";
        exit(0);
    }   

    while (k <= have - d[n]) {
        have -= d[n];
        --n;
    }

    int del = have - k;
    vector <int> pr;    
    for (int i = n / 2 + 1; i <= n; ++i) {
        pr.push_back(i);
    }
    sort(pr.begin(), pr.end(), comp);

    for (int e : pr) {
        if (d[e] <= del) {
            del -= d[e];
            dl[e] = 1;
        }
    }

    vector <int> ans;
    for (int i = 1; i <= n; ++i) {
        if (!dl[i]) ans.push_back(i);
    }

    cout << "Yes\n";
    cout << ans.size() << '\n';
    for (int e : ans) cout << e << ' ';
    cout << '\n';

    return 0;
}