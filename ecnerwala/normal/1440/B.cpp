#include<bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T;
while (T--) {
int N,K; cin >> N >> K;
vector<int> A(N*K);
for (auto& a : A) cin >> a;
int64_t ans = 0;
for (int i = 1; i <= K; i++) {
ans += A[N*K-i*(N/2+1)];
}
cout << ans << '\n';
}
}