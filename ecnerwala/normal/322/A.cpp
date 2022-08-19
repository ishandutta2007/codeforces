#include<iostream>

using namespace std;

main() {
int n, m; cin >> n >> m;
cout << n + m - 1 << '\n';
for(int i = 1; i <= n; i++) {
cout << i << ' ' << 1 << '\n';
}
for(int i = 2; i <= m; i++) {
cout << n << ' ' << i << '\n';
}
return 0;
}