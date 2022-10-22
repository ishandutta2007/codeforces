#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push push_back
const int N = 3e5 + 7;
int a[N], b[N], d[N];
struct Move {
    int i, j, r;
};  
vector <Move> ans;
int per[N];
bool comp(int i, int j) {
    return a[i] < a[j];
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) per[i] = i;
    sort(per, per + n, comp);

    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a, a + n); sort(b, b + n);

    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) {
        s1 += a[i]; s2 += b[i];
    }   
    if (s1 != s2) {
        cout << "NO\n";
        exit(0);
    }   

    for (int i = 0; i < n; ++i) {
        d[i] = b[i] - a[i];
    }   
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += d[i];
        if (cur < 0) {
            cout << "NO\n";
            exit(0);
        }   
    }   
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        cur += d[i];
        if (cur > 0) {
            cout << "NO\n";
            exit(0);
        }   
    }   

    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] > 0) {
            while (d[i]) {
                while (d[ptr] >= 0) ++ptr;
                if (abs(d[i]) <= abs(d[ptr])) {
                    ans.push({per[i], per[ptr], d[i]});
                    d[ptr] += d[i];
                    d[i] = 0;
                }
                else {
                    ans.push({per[i], per[ptr], abs(d[ptr])});
                    d[i] += d[ptr];
                    d[ptr] = 0;
                }   
            }
        }   
    }   

    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto e : ans) cout << e.i + 1 << ' ' << e.j + 1 << ' ' << e.r << '\n';
}