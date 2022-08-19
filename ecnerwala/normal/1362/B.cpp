#include<bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T;
while (T--) {
int N; cin >> N; vector<bool> has(1024);
vector<int> vals(N);
for (int i = 0; i < N; i++) { cin >> vals[i]; has[vals[i]] = true; }
for (int v = 1; true; v++) {
if (v == 1024) { cout << -1 << '\n'; break; }
vector<bool> nhas(1024);
for (int a : vals) nhas[v ^ a] = true;
if (has == nhas) { cout << v << '\n'; break; }
}
}
}