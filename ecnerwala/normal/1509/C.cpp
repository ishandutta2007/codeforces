#include <bits/stdc++.h>
int main() {
using namespace std;
int N; cin >> N;
vector<int> A(N); for (auto& a : A) cin >> a;
sort(A.begin(), A.end());
vector<int64_t> dp(N+1, 0);
for (int l = 0; l < N; l++) {
for (int i = 0; i < N-l; i++) {
dp[i] = min(dp[i], dp[i+1]) + A[i+l] - A[i];
}
}
cout << dp[0] << '\n';
}