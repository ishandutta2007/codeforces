#include<bits/stdc++.h>
using namespace std;
const int primes[4] = {2, 3, 5, 7};
int main() {
long long n; cin >> n;
long long res = 0;
for(int m = 0; m < 16; m++) {
long long val = n;
for(int i = 0; i < 4; i++) if(m & (1 << i)) val /= primes[i];
for(int i = 0; i < 4; i++) if(m & (1 << i)) val *= -1;
res += val;
}
cout << res << '\n';
}