#include<bits/stdc++.h>
using namespace std;

int n, k;
int s[200000];

int main() {
cin >> n >> k;
k = min(k, n);
for(int i = 0; i < n; i++) cin >> s[i];
int res = 0;
for(int i = 0; i < n - k; i ++) {
res = max(s[2 * n - 2 * k - 1 - i] + s[i], res);
}
for(int i = 2 * n - 2 * k; i < n; i++) {
res = max(res, s[i]);
}
cout << res << '\n';
return 0;
}