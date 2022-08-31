#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6;
const int maxm = 1e6;
int n;
int dp[maxn];
int ndp[maxn];
int m;
pair<int, pair<int, int>> e[maxn];

int main() {
ios_base::sync_with_stdio(0);
cin >> n >> m;
for(int i = 0; i < m; i++) {
cin >> e[i].second.first >> e[i].second.second >> e[i].first;
}
sort(e, e + m);
int res = 0;
for(int i = 0; i < m; ) {
int st = i;
int v = e[i].first;
while(i < m && e[i].first == v) {
int u = e[i].second.first, v = e[i].second.second;
ndp[v] = max(ndp[v], dp[u] + 1);
i++;
}
i = st;
while(i < m && e[i].first == v) {
int u = e[i].second.first, v = e[i].second.second;
dp[v] = ndp[v];
res = max(res, dp[v]);
i++;
}

}
cout << res << '\n';
return 0;
}