#include <bits/stdc++.h>
using namespace std;

int main() {
int n; cin >> n;
int cnt = 0;
for (int i = 0; i < n; i++) {
int x, y; cin >> x >> y;
if (x > 0) cnt ++;
}
if (cnt <= 1 || cnt >= n-1) {
cout << "YES\n";
} else cout << "NO\n";
}