#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
const int INF = 1e9 + 7;
string a[MAXN];
int b[MAXN], mn[MAXN];
vector <int> vpl[MAXN], vmn[MAXN];
bool comp1(int i, int j) {
    return mn[i] > mn[j];
}   
bool comp2(int i, int j) {
    return b[i] < b[j];
}   
signed main() {
    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int c = 0;
        mn[i] = 0;
        for (int j = 0; j < (int)a[i].size(); ++j) {
            if (a[i][j] == '(') ++c;
            else --c;
            mn[i] = min(mn[i], c);
        }   
        b[i] = c;
    }   

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) ans += mn[i] == 0;
    }   
    ans >>= 1;

    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            if (b[i] > 0) {
                if (mn[i] == 0) {
                    vpl[b[i]].push_back(i);
                }
            }
            else {
                vmn[-b[i]].push_back(i);
            }   
        }   
    }   

    for (int i = 0; i < MAXN; ++i) {
        sort(vmn[i].begin(), vmn[i].end(), comp1);
        sort(vpl[i].begin(), vpl[i].end(), comp2);
        int u = 0;
        for (int p : vmn[i]) {
            while (u < (int)vpl[i].size() && b[vpl[i][u]] + mn[p] < 0) {
                ++u;
            }   
            if (u < (int)vpl[i].size()) {
                ++ans;
                ++u;
            }   
        }   
    }   

    cout << ans << '\n';
}