#include <bits/stdc++.h>

int main() {
using namespace std;
int T; cin >> T;
while (T--) {
int N; cin >> N;
if (N & 1) { for (int i = 0; i < N-3; i += 2) cout << i+2 << ' ' << i+1 << ' ';
cout << N << ' ' << N-2 << ' ' << N-1 << '\n';
} else {
for (int i = 0; i < N; i += 2) cout << i+2 << ' ' << i+1 << '\n';
}
}
}