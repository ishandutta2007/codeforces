#include<iostream>

using namespace std;

int main() {
int n ;cin >> n;
if(n <=2) {
cout << n << '\n'; return 0;
}
int cur = 2; int max = 2;
int a, b; cin >> a >> b;
for(int i = 2; i < n; i++) {
int c; cin >> c;
if(c == a + b) {
cur ++;if(cur > max) max = cur;} else cur = 2;
a = b;
b = c;
}
cout << max << '\n';
return 0;
}