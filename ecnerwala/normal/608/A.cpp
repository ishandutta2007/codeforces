#include<bits/stdc++.h>
using namespace std;

int main() {
int res = 0;
int n; cin >> n;
for(int i = 0; i <= n; i++) {
int f, t; cin >> f;
if(i) cin >> t;
else t = 0;
res = max(res, f + t);
}
cout << res << '\n';
}