#include <bits/stdc++.h>
int main() {
using std::cin, std::cout;
int T; cin >> T;
while (T--) {
int N; cin >> N;
int prev = -1;
bool good = N % 2 == 0;
for (int i = 0; i < N; i++) { int a; cin >> a; good = good || (prev >= a); prev = a; }
cout << (good ? "YES" : "NO") << '\n';
}
}