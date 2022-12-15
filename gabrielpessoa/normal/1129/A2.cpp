#include <bits/stdc++.h>
using namespace std;

const int ms = 20005;

typedef long long ll;
typedef pair<int, int> ii;

priority_queue<ii> pq[ms];
int a[ms], b[ms];
int dist[ms];
int qnt[ms];

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    memset(dist, 63, sizeof dist);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        if(a[i] > b[i]) b[i] += n;
        b[i] -= a[i];
        dist[a[i]] = min(dist[a[i]], b[i]);
        qnt[a[i]]++;
    }
    for(int i = 0; i < n; i++) {
        int ans = 0;
        for(int j = i; j < n+i; j++) {
            int k = j % n;
            if(qnt[k]) {
                int d = j - i + n * (qnt[k] - 1) + dist[k];
                ans = max(ans, d);
            }            
        }
        cout << ans << ' ';
    }
    cout << '\n';
}