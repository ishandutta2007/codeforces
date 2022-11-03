#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int N = 2000 + 13;

int n;
int a[N];
int dp[N];

int get(int x) {
    for(int i = 0; i < n; i++)
        dp[i] = i;

    int ans = INF;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++)
            if((i - j) * 1ll * x >= abs(a[i] - a[j]))
                dp[i] = min(dp[i], dp[j] + i - j - 1);

        ans = min(ans, dp[i] + n - i - 1);
    }

    return ans;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n == 1) {
        cout << 0;
        return 0;
    }

    int l = -1, r = 2e9 + 13;
    while(r - l > 1) {
        int m = (l * 1ll + r) / 2;

//        cout << m << ' ' << get(m) << endl;

        if(get(m) <= k)
            r = m;
        else
            l = m;
    }

    cout << r;
}