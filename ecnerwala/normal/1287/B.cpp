#include<bits/stdc++.h>
using namespace std;
int main() {
int N, K; cin >> N >> K;
set<vector<int>> vecs;
int ans = 0;
while (N--) {
string S; cin >> S;
vector<int> cur(K);
for (int i = 0; i < K; i++) cur[i] = S[i]/3%3;
for (const auto& v : vecs) {
vector<int> cnd(K);
for (int i = 0; i < K; i++) cnd[i] = (6 - cur[i] - v[i]) % 3;
if (vecs.count(cnd)) ans++;
}
vecs.insert(cur);
}
cout << ans/2 << '\n';
}