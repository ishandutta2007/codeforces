#include <iostream>
#include <algorithm>
using namespace std;

int main() {
int n; cin >>n; if(n / 2 % 2 == 1) {cout << "-1\n"; return 0;}
int a[200000] = {0};
for(int i = 0; i < n; i++) a[i] = i + 1;
for (int i=0; i<n/2; i+=2) {
swap(a[i], a[i+1]); swap(a[n-i - 1], a[n - i - 2]); swap(a[n - i - 2], a[i + 1]);}
for (int i=0; i<n; i++) cout << a[i] << ' ';
cout << '\n'; return 0;}