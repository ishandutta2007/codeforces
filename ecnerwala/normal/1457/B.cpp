#include<bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {
int N, K; cin >> N >> K;
vector<int> C(N);
for (auto& c : C) cin >> c;
int ans = N;
for (int t = 1; t <= 100; t++) {
int cur = 0;
for (int i = 0; i < N; i++) {
if (C[i] != t) i += K-1, cur++;
}
ans = min(ans, cur);
}
cout << ans << '\n';
}
}