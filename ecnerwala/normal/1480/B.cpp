#include <bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T;
while (T--) {

int64_t A, B; int N; cin >> A >> B >> N;
vector<int> x(N); for (int& a : x) cin >> a;
for (int a : x) {
int b; cin >> b;
B -= (b + A - 1) / A * a;
}
cout << (B + *max_element(x.begin(), x.end()) > 0 ? "YES" : "NO") << '\n';
}
}