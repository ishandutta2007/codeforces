#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back

const int C = 26;
int cnt[C];
bool rem(int n) {
    return n%2;
}   
void solve(int i, int add, int w) {
    if (i == C) {
        if (abs(w) <= add) {
            cout << "Yes" << endl;
            exit(0);
        }   
        else {
            return;
        }   
    }   

    int x = cnt[i];
    x += add;
    if (rem(x) ^ rem(w)) {
        if (add) {
            x--;
        }   
        else {
            return;
        }   
    }   

    if (rem(w)) {
        solve(i + 1, x/2, (w - 1) / 2);
        solve(i + 1, x/2, (w + 1) / 2);
    }   
    else {
        solve(i + 1, x/2, w/2);
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, T;
    cin >> n >> T;
    string s;
    cin >> s;
    for (int i = 0; i < n - 2; ++i)
        cnt[s[i]-'a']++;

    int w = T;
    w -= 1 << (s[n - 1] - 'a');
    w += 1 << (s[n - 2] - 'a');

    solve(0, 0, w);
    cout << "No" << endl;
}