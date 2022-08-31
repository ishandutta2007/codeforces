#include<bits/stdc++.h>

using namespace std;

int main() {
int n, m; cin >> n >> m;
int res = (n + 1) / 2;
while(res % m != 0) res++;
if(res > n) cout << -1 << '\n';
else cout << res << '\n';
return 0;
}