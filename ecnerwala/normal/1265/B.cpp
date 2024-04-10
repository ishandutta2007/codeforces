#include<bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {
int N; cin >> N;
vector<int> P(N);
for (int i = 0; i < N; i++) { int v; cin >> v; P[v-1] = i; }
int mi = N, ma = -1;
for (int i = 0; i < N; i++) {
mi = min(mi, P[i]); ma = max(ma, P[i]);
cout << (ma - mi == i);
}
cout << '\n';
}
}