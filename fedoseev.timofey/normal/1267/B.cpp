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
    string s; cin >> s;
    string t; vector <int> a;
    char c = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == c) {
            ++cnt;
        }   
        else {
            t += c;
            a.app(cnt);
            c = s[i];
            cnt = 1;
        }                         
    }   
    t += c;
    a.app(cnt);
    int n = t.size();
    if (n % 2 == 0) {
        cout << "0\n";
        return 0;
    }   
    string tmp = t;
    reverse(all(tmp));
    if (t != tmp) {
        cout << "0\n";
        return 0;
    }   
    if (a[n >> 1] < 2) {
        cout << "0\n";
        return 0;
    }   
    for (int i = 0; i < (n >> 1); ++i) {
        if (a[i] + a[n - i - 1] < 3) {
            cout << "0\n";
            return 0;
        }   
    }   
    cout << a[n >> 1] + 1 << '\n';
}