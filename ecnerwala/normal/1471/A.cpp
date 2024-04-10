#include<bits/stdc++.h>
int main(){using namespace std;int T; cin >> T; while (T--) {
int N, X; cin >> N >> X; int64_t a = 0, b = 0; while (N--) { int v; cin >> v; a += v; b += (v + X - 1) / X; } cout << (a + X - 1) / X << ' ' << b << '\n';
}}