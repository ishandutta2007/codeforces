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
const int N = 1e6 + 7;
int n, q, ans[N];
void upd1(int &p, int sh) {
    p += sh;
    p = (p % n + n) % n;        
}   
void upd2(int &p) {
    p ^= 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> q;
    int p1 = 0, p2 = 1;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int sh; cin >> sh;
            upd1(p1, sh); upd1(p2, sh);
        }   
        else {
            upd2(p1); upd2(p2);
        }   
    }   
    for (int i = 0; i < n / 2; ++i) {
        ans[(p1 + i * 2) % n] = 1 + i * 2;
        ans[(p2 + i * 2) % n] = 2 + i * 2;
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
}