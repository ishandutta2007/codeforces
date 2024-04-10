#include<bits/stdc++.h>
using namespace std;
#define int long long
int len(int n) {
    int ans = 1;
    int f = 7;
    while (f < n) {
        ++ans;
        f *= 7;
    }   
    return ans;
}    
bool used[10];
vector <int> a;
int n, m;
int l, r;
bool check() {
    int vl = 0;
    for (int i = 0; i < l; ++i) {
        vl = vl * 7 + a[i];
    }
    int vr = 0;
    for (int i = l; i < a.size(); ++i) {
        vr = vr * 7 + a[i];
    }   
    return vl < n && vr < m;
}   
int ans = 0;
void gen(int i, int n) {
    if (i == n) {
        //for (auto e : a) cout << e << ' ';
        //cout << '\n';
        ans += check();
        return;
    }   
    for (int c = 0; c < 7; ++c) {
        if (!used[c]) {
            used[c] = 1;
            a.push_back(c);
            gen(i + 1, n);
            used[c] = 0;
            a.pop_back();
        }   
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    l = len(n); r = len(m);
    if (l + r > 7) {
        cout << "0\n";
    }   
    else {
        gen(0, l + r);
        cout << ans << '\n';
    }   
}