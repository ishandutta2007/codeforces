#include<bits/stdc++.h>

using namespace std;

int n, k, d;
int v[2000];

int main() {
ios_base::sync_with_stdio(0);
cin >> n >> k >> d;
v[n - 1] = n - 1;
for(int i = 0; i < d; i++) v[n - 1] /= k;
if(v[n - 1]) {
cout << -1 << '\n';
return 0;
}
for(int i = 0; i < n; i++) v[i] = i;
for(int j = 0; j < d; j++) {
for(int i = 0; i < n; i++) cout << v[i] % k + 1 << ' ', v[i] /= k;
cout << '\n';
}
return 0;
}