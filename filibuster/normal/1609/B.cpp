#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 30000 + 13;
const int K = 113;

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i < n - 2; i++) {
        if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
            cnt++;
    }

    for(int j = 0; j < q; j++) {
        int ind;
        char c;
        cin >> ind >> c;

        ind--;

        for(int i = max(0, ind - 2); i <= min(n - 3, ind); i++) {
            if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
                cnt--;
        }

        s[ind] = c;

        for(int i = max(0, ind - 2); i <= min(n - 3, ind); i++) {
            if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
                cnt++;
        }

        cout << cnt << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}