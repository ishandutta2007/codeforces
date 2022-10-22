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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        string s = to_string(i);
        string t = s;
        sort(all(t));
        t.resize(unique(all(t)) - t.begin());
        if (s.size() == t.size()) {
            cout << i << '\n';
            exit(0);
        }   
    }   
    cout << "-1\n";
}