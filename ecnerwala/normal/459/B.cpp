#include<bits/stdc++.h>

using namespace std;

int main() {
int mi = 1e9 + 7;
long long mic = 0;
int ma = 0;
long long mac = 0;
long long n; cin >> n;
for(int i = 0; i < n; i++) {
int v; cin >> v;
if(v < mi) mi = v, mic = 0;
if(v == mi) mic ++;
if(v > ma) ma = v, mac = 0;
if(v == ma) mac ++;
}
if(mi == ma) cout << 0 << ' ' << n * (n - 1) / 2 << '\n';
else cout << ma - mi << ' ' << mic * mac << '\n';
return 0;
}