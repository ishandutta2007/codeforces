#include <bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T; while (T--) {
int N; cin >> N;
vector<int> V(2*N+1, 0);
for (int i = 1; i <= N; i++) {
int a; cin >> a; V[a] = i;
}
int ans = 0;
for (int i = 1; i*(i+1) <= 2*N; i++) {
for (int j = i+1; j <= 2*N/i; j++) {
if (V[i] && V[j] && V[i]+V[j] == i*j) ans++;
}
}
cout << ans << '\n';
}
}