#include<bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T; while (T--) {
int N; cin >> N;
std::vector<int> A(N);
for (auto& a : A) cin >> a;
int x = 0, y = 0;
for (auto a : A) {
int b; cin >> b;
x = max(x, min(a,b));
y = max(y, max(a,b));
}
cout << x*y << '\n';
}
}