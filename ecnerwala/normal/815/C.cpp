#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main() {
int N; cin >> N;
i64 B; cin >> B;
vector<i64> C(N), D(N);
vector<int> X(N); X[0] = -1;
for (int i = 0; i < N; i++) {
cin >> C[i] >> D[i];
if (i) cin >> X[i], X[i] --;
}

auto mergeVecs = [&](vector<i64> a, vector<i64> b) {
vector<i64> c(int(a.size()) + int(b.size()) - 1, B+1);
for (int i = 0; i < int(a.size()); i++) {
for (int j = 0; j < int(b.size()); j++) {
c[i+j] = min(c[i+j], a[i] + b[j]);
}
}
return c;
};

vector<vector<i64>> dpTake(N, vector<i64>({0}));
vector<vector<i64>> dpOther(N, vector<i64>({0}));
for (int i = N-1; i >= 0; i--) {
// add yourself
int Z = int(dpOther[i].size());
dpTake[i].insert(dpTake[i].begin(), 0);
for (int j = 1; j <= Z; j++) dpTake[i][j] += C[i] - D[i];
for (int j = 0; j < Z; j++) dpTake[i][j] = min(dpTake[i][j], dpOther[i][j]);

dpOther[i].push_back(dpOther[i].back() + C[i]);
for (int j = Z; j >= 1; j--) dpOther[i][j] = min(dpOther[i][j], dpOther[i][j-1] + C[i]);

if (i == 0) break;
// add yourself to parent
dpTake[X[i]] = mergeVecs(dpTake[X[i]], dpTake[i]);
dpOther[X[i]] = mergeVecs(dpOther[X[i]], dpOther[i]);
}

int ans = 0;
while (ans < N && dpTake[0][ans+1] <= B) ans++;
cout << ans << '\n';
}