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
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    if (k == 0) {
        cout << s << '\n';
        exit(0);
    }   
    if (n == 1) {
        cout << "0\n";
        exit(0);            
    }   
    for (int i = 0; i < n; ++i) {
        int mn = '0' + (i == 0);
        if (s[i] > mn && k) {
            s[i] = mn; --k;
        }   
    }   
    cout << s << '\n';
}