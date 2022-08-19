#include<bits/stdc++.h>
using namespace std;

int main() {
int n; cin >> n;
int res = 0;
for(int i = 0; i < n; i++ ){
int p, q; cin >> p >> q;
res += (q - p) >= 2;
}
cout << res << '\n';
return 0;
}