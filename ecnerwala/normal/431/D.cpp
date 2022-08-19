#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 4e18;

ll choose[100][100];

int main() {
for(int n = 0; n < 80; n++) {
choose[n][0] = choose[n][n] = 1;
for(int i = 1; i < n; i++) choose[n][i] = min(INF, choose[n - 1][i - 1] + choose[n - 1][i]);
}

ll M, K;
cin >> M >> K;
K--;
if(K == 0) {cout << 1 << '\n';return 0;}
ll res = 0;
for(int i = 62; i >= 0; i--) {
ll v = (i >= K) ? choose[i][K] : 0;
if(M >= v) M -= v, res += (1ll << i), K--;
}
assert(M == 0);
cout << min(max(res, 1ll),INF/4) << '\n';

return 0;
}