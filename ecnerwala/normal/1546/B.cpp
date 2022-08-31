#include <bits/stdc++.h>
int main() {
using namespace std;
ios_base::sync_with_stdio(false); cin.tie(nullptr);
int T; cin >> T;
while (T--) {
int N, M; cin >> N >> M;
string V(M, '\0');
for (int i = 0; i < 2*N-1; i++) {
string s; cin >> s;
for (int j = 0; j < M; j++) V[j] ^= s[j];
}
cout << V << '\n' << flush;
}
}