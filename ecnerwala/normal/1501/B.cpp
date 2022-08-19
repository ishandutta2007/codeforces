#include <bits/stdc++.h>
int main() {
using namespace std;
ios_base::sync_with_stdio(false); cin.tie(nullptr);
int T; cin >> T;
while (T--) {
int N; cin >> N;
vector<bool> ans(N, false);
vector<int> todo; todo.reserve(N);
for (int i = 0; i < N; i++) {
todo.push_back(i);
int a; cin >> a;
while (!todo.empty() && todo.back() >= i+1-a) {
ans[todo.back()] = true;
todo.pop_back();
}
}
for (int i = 0; i < N; i++) cout << ans[i] << ' ';
cout << '\n';
}}