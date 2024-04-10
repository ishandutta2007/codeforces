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
int sum(vector <int> &a) {
    int ans = 0;
    for (int e : a) ans += e;
    return ans;        
}   
void add(int &i, vector <int> &a, vector <int> &ans, int x) {
    i = x;
    --a[x];
    ans.app(x);
}   
void solve(int i, vector <int> a) {
    if (!a[i])
        return;
    --a[i];
    vector <int> ans = {i};
    while (sum(a)) {
        if (i == 0) {
            if (a[1] == 0) break;
            add(i, a, ans, 1);
        }
        else if (i == 1) {
            if (a[0]) 
                add(i, a, ans, 0);
            else if (a[2] == 0)
                break;
            else 
                add(i, a, ans, 2);
        }   
        else if (i == 2) {
            if (a[3]) 
                add(i, a, ans, 3);
            else if (a[1] == 0)
                break;
            else 
                add(i, a, ans, 1);
        }   
        else if (i == 3) {
            if (a[2] == 0) break;
            add(i, a, ans, 2);
        }   
    }   
    if (sum(a) == 0) {
        cout << "YES\n";
        for (int e : ans) cout << e << ' '; cout << '\n';
        exit(0);
    }
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    vector <int> a(4);
    for (int i = 0; i < 4; ++i)
        cin >> a[i];
    for (int f = 0; f < 4; ++f) 
        solve(f, a);        
    cout << "NO\n";        
}