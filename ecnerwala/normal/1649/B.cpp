#include <bits/stdc++.h>

int main() {
using std::cin; using std::cout;
int T; cin >> T;
while (T--) {
int N; cin >> N;
int mx = 0;
int64_t tot = 0;
while (N--) {
int a; cin >> a; mx = std::max(mx, a);
tot += a;
}
cout << std::max<int64_t>(bool(tot), mx * 2 - tot) << '\n';
}
}