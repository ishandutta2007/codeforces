#include<bits/stdc++.h>
int main() {
using namespace std;
ios_base::sync_with_stdio(false), cin.tie(nullptr);
int T; cin >> T; while (T--) {
int N; cin >> N; vector<int> S(N+1); for (int i = 1; i <= N; i++) cin >> S[i];
vector<int> dp(N+1, 1);
for (int i = 1; i <= N; i++) {
for (int j = i+i; j <= N; j += i) if (S[j] > S[i]) dp[j] = max(dp[j], dp[i]+1);
}
cout << *max_element(dp.begin(), dp.end()) << '\n';
}
}