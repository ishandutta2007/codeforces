#include<bits/stdc++.h>
using namespace std;

void go() {
int N; string S, T; cin >> N >> S >> T;
vector<pair<int, int>> ops;
for (int i = 0; i < N; i++) {
 if (S[i] == T[i]) goto done;
 for (int j = i+1; j < N; j++) {
  if (S[j] == S[i]) {
   swap(S[j], T[i]); ops.emplace_back(j, i);
   goto done;
  }
  if (T[j] == S[i]) {
   swap(S[j], T[j]); ops.emplace_back(j, j);
   swap(S[j], T[i]); ops.emplace_back(j, i);
   goto done;
  }
 }
 cout << "No" << '\n'; return;
done:;
}
cout << "Yes" << '\n';
cout << ops.size() << '\n';
for (auto op : ops) cout << op.first+1 << ' ' << op.second+1 << '\n';
}

int main() { int K; cin >> K; while (K--) go(); }