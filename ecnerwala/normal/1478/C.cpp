#include<bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T;
while (T--) {
cout << ([]() -> bool {
int N; cin >> N;
vector<int64_t> D(2*N); for (auto& d : D) cin >> d;
sort(D.begin(), D.end());
for (int i = 0; i < N; i++) if (D[2*i] % 2 || D[2*i] != D[2*i+1]) return false;
int64_t tot_sum = D[0] / 2;
for (int i = 1; i < N; i++) { int64_t v = D[2*i]/2 - D[2*i-2]/2; if (v == 0) return false; if (v % i) return false; tot_sum -= v / i * (N-i); if (tot_sum <= 0) return false; }
if (tot_sum % N) return false;
return true;
}() ? "YES" : "NO") << '\n';
}
}