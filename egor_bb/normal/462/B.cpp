#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){


int n, k, a[26];
for (int i = 0; i < 26; i++) a[i] = 0;
char t;
cin >> n >> k;
for (int i = 0; i < n; i++) {
cin >> t;
a[t - 'A']++;
}
sort (a, a + 26);
long long ans = 0, s = 0;
for (int i = 25; i >= 0; i--){
if (a[i] + s <= k) ans += 1ll * a[i] * a[i];
else {
ans += 1ll * (k - s)*(k - s);
break;
}
s += a[i];
}
cout << ans;
}