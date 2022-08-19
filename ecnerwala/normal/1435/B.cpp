#include<bits/stdc++.h>
using namespace std;

int main() {
int T; cin >> T;
while (T--) {
int N, M; cin >> N >> M;
vector<int> idx(N*M);
for (int i = 0; i < N; i++) {
for (int j = 0; j < M; j++) {
int v; cin >> v; v--;
idx[v] += j;
}
}
for (int j = 0; j < M; j++) {
for (int i = 0; i < N; i++) {
int v; cin >> v; v--;
idx[v] += i*M;
}
}
vector<int> ans(N*M);
for (int i = 0; i < N*M; i++) ans[idx[i]] = i+1;
for (int i = 0; i < N*M; i++) cout << ans[i] << ' ';
cout << '\n';
}
}