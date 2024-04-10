#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2e5 + 7, C = 26;
int pref[C][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s;
    cin >> s;
    int n = s.size();
    for (int c = 0; c < C; ++c) {
        for (int i = 0; i < n; ++i)
            pref[c][i + 1] = pref[c][i] + (s[i] == 'a' + c);
    }   
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        if (l == r) {
            cout << "Yes\n";
            continue;
        }   
        int cnt = 0;
        for (int c = 0; c < C; ++c)
            cnt += pref[c][r + 1] > pref[c][l];
        if (cnt <= 2) {
            if (s[l] != s[r])
                cout << "Yes\n";
            else
                cout << "No\n";
        }   
        else {
            cout << "Yes\n";
        }   
    }   
}