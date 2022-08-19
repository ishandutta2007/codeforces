#include<bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {
int N, M, R, C; cin >> N >> M >> R >> C;
cout << max(R-1,N-R)+max(C-1,M-C) << '\n';
}
}