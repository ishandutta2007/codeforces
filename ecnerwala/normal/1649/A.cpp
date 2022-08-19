#include <bits/stdc++.h>

int main() {
using std::cin; using std::cout;
int T; cin >> T;
while (T--) {
int N; cin >> N;
int first = -1, last = -3;
for (int i = 0; i < N; i++) {
int a; cin >> a; if (!a) {
last = i;
if (first == -1) first = i;
}
}
cout << last - first + 2 << '\n';
}
}