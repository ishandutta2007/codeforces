#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

typedef long long ll;

const int ms = 5005;
const int inf = 0x3f3f3f3f;


int n;
int dp[ms][2*ms];
int v[ms];

int get(int a, int b) { //(b = QNTS DE 1)
    int shf = (b+ms);
    int &ans = dp[a][shf];
    if(ans != -1) return ans;
    if(a == n) return ans = (b == 0) ? 0 : inf;
    if(v[a]) {
        ans = get(a+1, b+1) + abs(b+1);
    } else {
        ans = min(get(a+1, b-1) + abs(b-1), get(a+1, b) + abs(b));
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << get(0, 0) << endl;
    return 0;
}