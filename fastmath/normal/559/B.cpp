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

map <string, int> dp;
map <ii, int> dpp;

int ptr = 1;
int solve(string s) {
    if (dp.find(s) != dp.end())
        return dp[s];
    if (s.size() & 1) {
        dp[s] = ptr;
        ++ptr;
        return ptr - 1;
    }   
    int m = (int)s.size() / 2;
    string l = s.substr(0, m), r = s.substr(m, m);
    int a = solve(l), b = solve(r);
    if (b < a)
        swap(a, b);
    if (dpp.find(mp(a, b)) != dpp.end()) {
        return dp[s] = dpp[mp(a, b)];
    }   
    else {
        dp[s] = dpp[mp(a, b)] = ptr;
        ++ptr;
        return dp[s];        
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string a, b;
    cin >> a >> b;

    if (solve(a) == solve(b)) 
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}