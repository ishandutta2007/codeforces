#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
1
3
caa
aca

1
3
caa
aca
*/

int ft[N];

void add(int i, int x) {
    for(; i < N; i |= (i + 1))
        ft[i] += x;
}

int get(int i) {
    int res = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1)
        res += ft[i];
    return res;
}

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

//    cout << s << ' ' << t << endl;

    if(s < t) {
        cout << 0 << endl;
        return;
    }

    string sorted = s;
    sort(sorted.begin(), sorted.end());

    if(sorted >= t) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> pos(A);
    for(int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    vector<int> ind(A, 0);

    for(int i = 0; i < n; i++) {
        ft[i] = 0;
    }

    li ans = INF64;
    li res = 0;
    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << res << endl;
        for(int x = 0; x < t[i] - 'a'; x++) {
            if(ind[x] < pos[x].size()) {
                int j = pos[x][ind[x]];
//                cout << i << ' ' << x << ' ' << j << ' ' << res + j - get(j) << endl;
                ans = min(ans, res + j - get(j));
            }
        }

        int x = t[i] - 'a';

//        cout << i << ' ' << t[i] << ' ' << int(t[i]) << ' ' << int('a') << ' ' << x << ' ' << ind[x] << ' ' << pos[x].size() << endl;

        if(ind[x] == pos[x].size())
            break;

        int j = pos[x][ind[x]];
        res += j - get(j);

        add(j, 1);

        ind[x]++;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}