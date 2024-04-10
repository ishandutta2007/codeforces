#include<bits/stdc++.h>

int main() {
using namespace std;
ios_base::sync_with_stdio(false), cin.tie(nullptr);
int T; cin >> T;
while (T--) {
int64_t N, M; cin >> N >> M;
cout << (N*M<=N+M ? "YES":"NO") << '\n';
}
}