#include<bits/stdc++.h>
using namespace std;

int main() {
int T; cin >> T;
while (T--) {
int N; cin >> N;
vector<int> Q(N);
for (int i = 0; i < N; i++) cin >> Q[i];
stack<int> cnds;
int prv = 0;
vector<int> res;
bool bad = false;
for (int i = 0; i < N; i++) {
if (Q[i] < prv) {
bad = true; break;
}
while (prv < Q[i]) cnds.push(++prv);
if (cnds.empty()) { bad = true; break; }
res.push_back(cnds.top()); cnds.pop();
}
if (bad) cout << -1 << '\n';
else for (int i = 0; i < N; i++) cout << res[i] << " \n"[i+1==N];
}
}