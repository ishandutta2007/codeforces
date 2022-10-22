#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int f[N];
int getp(string s) {
    f[0] = 0;
    for (int i = 1; i < (int)s.size(); ++i) {
        int p = f[i - 1];
        while (p && s[p] != s[i]) {
            p = f[p - 1];
        }   
        if (s[p] == s[i]) {
            f[i] = p + 1;
        }   
        else {
            f[i] = 0;
        }   
    }   
    return f[(int)s.size() - 1];
}   
bool check(int *a, int *b) {
    return a[0] <= b[0] && a[1] <= b[1];
}   
void del(int *a, int *b) {
    b[0] -= a[0]; b[1] -= a[1];
}   
int cs[2], ct[2];
int add[2];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s, t;
    cin >> s >> t;
    int p = getp(t);
    for (char c : s) ++cs[c - '0'];
    for (char c : t) ++ct[c - '0'];
    for (char c : t.substr(p, t.size() - p)) ++add[c - '0'];
    if (!check(ct, cs)) {
        cout << s << '\n';
        exit(0);
    }            
    else {
        cout << t;
        del(ct, cs);
        while (check(add, cs)) {
            cout << t.substr(p, t.size() - p);
            del(add, cs);
        }   
        while (cs[0]--) cout << '0';
        while (cs[1]--) cout << '1';
        cout << '\n';
    }   
}