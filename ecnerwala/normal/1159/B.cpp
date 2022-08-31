#include<bits/stdc++.h>
using namespace std;

int main() {
int N; cin >> N;
int res = int(1.1e9);
for (int i = 0; i < N; i++) {
int a; cin >> a;
res = min(res, a / max(i,N-i-1));
}
cout << res << '\n';
}