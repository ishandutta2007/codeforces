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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        sort(all(s));
        if (s[0] != '0') {
            cout << "cyan\n";
            continue;
        }
        s = s.substr(1, s.size() - 1);

        int sum = 0;
        for (char c : s)
            sum += c - '0';
        bool ch = 0;
        for (char c : s)
            ch |= (c - '0') % 2 == 0;
        if (sum % 3 == 0 && ch)
            cout << "red\n";
        else 
            cout << "cyan\n";
    }   
}