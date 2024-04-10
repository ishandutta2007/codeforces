#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, k;
string s;
bool can_del(char c) {
    int l = N, r = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == c) {
            l = min(l, i);
            r = max(r, i);
        }   
    }   
    return r - l + 1 <= k;
}  
string ans1 = "tokitsukaze", ans2 = "quailty", ans3 = "once again";
bool win(string s) {
    return can_del('0') || can_del('1');
}   
vector <int> pos[2];
int ml[2], mr[2];

void f(int l, int r, int t) {
    if (pos[t].size() && pos[t][0] < l) ml[t] = min(ml[t], pos[t][0]);
    auto p = upper_bound(pos[t].begin(), pos[t].end(), r);
    if (p != pos[t].end()) {
        ml[t] = min(ml[t], *p);
    }   

    if (pos[t].size() && pos[t].back() > r) mr[t] = max(mr[t], pos[t].back());
    p = lower_bound(pos[t].begin(), pos[t].end(), l);
    if (p != pos[t].begin()) {
        --p;
        mr[t] = max(mr[t], *p);
    }   
}   

bool col(int l, int r, int t) {
    for (int i = 0; i < 2; ++i) {
        ml[i] = N; mr[i] = -1;
    }   
    
    ml[t] = l; mr[t] = r;
    f(l, r, 0); f(l, r, 1);

    for (int i = 0; i < 2; ++i) {
        if (mr[i] - ml[i] + 1 <= k) {
            return 0;
        }   
    }   
    return 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        pos[s[i] - '0'].push_back(i);
    }   
    if (win(s)) {
        cout << ans1 << '\n';
        exit(0);
    }       
    for (int i = 0; i + k - 1 < n; ++i) {
        if (col(i, i + k - 1, 0)) {
            cout << ans3 << '\n';
            exit(0);
        }   
        if (col(i, i + k - 1, 1)) {
            cout << ans3 << '\n';
            exit(0);
        }   
    }   
    cout << ans2 << '\n';
}