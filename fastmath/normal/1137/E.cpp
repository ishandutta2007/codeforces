#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int INF = 1e9 + 7;
int B = 0, S = 0;
struct Line {
    int a, b;
};  
int L, R;
vector <Line> a;
void init() {
    L = 0; R = n - 1;
    a.push_back({0, 0});
}   
void addl(int k) {
    a.clear();
    R += k;
    a.push_back({0, -B});
}
int get(Line l) {
    return B + S * l.a + l.b;
}   
int dup(int a, int b) {
    return (a + b - 1) / b;
}   
int per(Line l, Line r) {
    //l.a < r.a
    //l.a * x + l.b <= r.a * x + r.b
    //l.b - r.b <= x * (r.a - l.a)
    return dup(l.b - r.b, r.a - l.a);
}   
void addr(int k) {
    Line l = {R + 1, -B - S * (R + 1)};
    R += k;
    if (a.back().b <= l.b) return;
    // sz - 2 ob sz - 1
    // sz - 1 ob l
    #define sz a.size()
    while (2 <= sz && per(a[sz - 2], a[sz - 1]) <= per(a[sz - 1], l)) a.pop_back();
    a.push_back(l);
}
void upd(int b, int s) {
    B += b;
    S += s;
}   
int cnt = 0;
void print() {
    ++cnt;
    int l = 0;
    int r = (int)a.size();
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (get(a[m - 1]) <= get(a[m])) r = m;
        else l = m;
    }   
    cout << a[l].a + 1 << ' ' << get(a[l]) << '\n';
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            cin >> k;
            addl(k);
        }
        else if (t == 2) {
            int k;
            cin >> k;
            addr(k);
        }
        else {
            int b, s;
            cin >> b >> s;
            upd(b, s);
        }   
        print();
    }   
}