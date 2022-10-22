#include<bits/stdc++.h>
using namespace std;
string w = "ACTG";
int dist(int a, int b) {
    return min(abs(a - b), 26 - abs(a - b));
}   
int get(string s) {
    int ans = 0;
    for (int i = 0; i < 4; ++i) ans += dist(s[i] - 'A', w[i] - 'A');
    return ans;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);                                        
    #endif
    int n; cin >> n;
    string s;
    cin >> s;
    const int INF = 1e9 + 8;
    int ans = INF;
    for (int i = 0; i + 3 < n; ++i) {
        ans = min(ans, get(s.substr(i, 4)));
    }   
    cout << ans << '\n';
}