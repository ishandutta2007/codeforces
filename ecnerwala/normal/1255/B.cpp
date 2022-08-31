#include<bits/stdc++.h>
using namespace std;

int main() {
int T; cin >> T;
while (T--) {
int N, M; cin >> N >> M;
int ta = 0;
for (int i = 0; i < N; i++) { int a; cin >> a; ta += a; }
if (N == 2 || M < N) { cout << -1 << '\n'; continue; }
cout << ta * 2 << '\n';
for (int i = 0; i < N; i++) {
cout << i+1 << ' ' << (i+1)%N + 1 << '\n';
}
}
}