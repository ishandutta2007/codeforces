#include <bits/stdc++.h>
int main() {
using namespace std;
ios_base::sync_with_stdio(false); cin.tie(nullptr);
int T; cin >> T; while (T--) {

int N; cin >> N;
vector<int> A(N); for (auto& a : A) cin >> a;

std::optional<int> pos_diff;
std::optional<int> neg_diff;
bool is_good = true;
for (int i = 0; i+1 < N; i++) {
int d = A[i+1] - A[i];
auto& v = (d < 0) ? neg_diff : pos_diff;
if (!v) v = d;
if (*v != d) { is_good = false; break; }
}

if (!is_good) { cout << -1 << '\n'; continue; }
if (!pos_diff || !neg_diff ) { cout << 0 << '\n'; continue; }

int m = *pos_diff - *neg_diff;
int c = *pos_diff;

for (int i = 0; i < N; i++) if (A[i] >= m) {
is_good = false;
}
for (int i = 0; i+1 < N; i++) if (A[i+1] != (A[i] +  c) % m) is_good = false;

if (!is_good) { cout << -1 << '\n'; continue; }
else { cout << m << ' ' << c << '\n'; }

}
}