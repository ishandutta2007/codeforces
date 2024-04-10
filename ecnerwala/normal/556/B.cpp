#include<bits/stdc++.h>

using namespace std;
int mod(int a, int m) { a %= m; return a < 0 ? a + m : a;}
int main() {
int n; cin >> n;
int v; cin >> v;
for(int i = 1; i < n; i++) {
int a; cin >> a;
a -= i;
if(i % 2) a *= -1;
a = mod(a, n);
if(a != v) {
cout << "No\n";
return 0;
}
}
cout << "Yes\n";
return 0;
}