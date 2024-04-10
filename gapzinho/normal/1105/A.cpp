#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1005;

int v[ms];

main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int n;
    cin >> n;
    pair<int, int> ans = {0x3f3f3f3f, -1};

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i <= 100; i++) {
        int cur = 0;
        for(int j = 0; j <n; j++) {
            int cost = 0x3f3f3f3f;
            for(int k = i-1; k <= i+1; k++) cost = min(cost, abs(v[j]-k));
            cur += cost;
        }
        ans = min(ans, {cur, i});
    }
    cout << ans.second << ' ' << ans.first << endl;
}