#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;

int add(int a, int b) {
    int res = a + b;
    if(res >= M)
        res -= M;
    return res;
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
1
6 1
WLLWLW
*/

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int fir = 0, lst = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L')
            fir++;
        else
            break;
    }

    for(int j = n - 1; j >= 0; j--)
        if(s[j] == 'L')
            lst++;
        else
            break;


    vector<int> a;
    int ans = 0;
    for(int i = fir; i < n - lst; i++) {
        if(s[i] == 'L') {
            if(i > 0 && s[i - 1] == 'L')
                a.back()++;
            else
                a.push_back(1);
        } else {
            ans++;
            if(i > 0 && s[i- 1] == 'W')
                ans++;
        }
    }

    if(ans == 0) {
        cout << max(0, k * 2 - 1) << endl;
        return;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < a.size(); i++) {
        if(a[i] <= k) {
            k -= a[i];
            ans += a[i] * 2 + 1;
        } else {
            ans += k * 2;
            k = 0;
            break;
        }
    }

    ans += min(k, lst + fir) * 2;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}