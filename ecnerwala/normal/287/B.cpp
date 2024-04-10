#include<iostream>
#include <algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int main() {
ll n, k; cin >> n >> k;
ll sum = k*(k-1)/2;
if(n - 1 > sum) { cout << -1 << '\n'; return 0;}
sum = 1;
if (n == 1) { cout << 0 << '\n'; return 0;}
for(ll i = k - 1; i > 0; i--) { sum += i;
if(sum >= n) {cout << k - i << '\n'; return 0;}} return 0;}