#include<iostream>

using namespace std;

int main() {
int n1 = 0, n2 = 0;
int n; cin >> n;
for(int i = 0; i< n; i++) { int w; cin >> w; if(w == 100) n1++; else n2++; }
int v = n1 + 2 * n2;
if(v % 2 == 1) {cout << "NO" << '\n'; return 0;}
v /= 2;
if(v % 2 == 1 && n1 == 0) {cout << "NO" << '\n'; return 0;}
cout << "YES" << '\n';
}