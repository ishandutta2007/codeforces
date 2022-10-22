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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    string a, b;
    char ax = '0', bx = '1';
    for (char c : s) {
        if (b.back() <= c) {
            ans += bx;
            b += c;
        }   
        else if (a.back() <= c) {
            ans += ax;
            a += c;
        }   
        else {
            cout << "NO" << endl;
            exit(0);
        }   
        if (b.empty() || (a.size() && b.back() < a.back())) {
            swap(a, b);
            swap(ax, bx);
        }
    }   
    cout << "YES" << endl << ans << endl;
}