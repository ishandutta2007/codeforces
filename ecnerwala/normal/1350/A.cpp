#include<bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T;
while (T--) {
int N, K; cin >> N >> K;
for (int v = 2; true; v++) if (N % v == 0) { N += v; K--; break; }
cout << N + 2 * K << '\n';
}
}