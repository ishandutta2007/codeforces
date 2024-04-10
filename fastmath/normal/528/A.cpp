#include<bits/stdc++.h>
using namespace std;
#define int long long
int w, h, n;
void upd(set <int> &s, multiset <int> &len, int x) {
    auto r = s.upper_bound(x);
    auto l = r; --l;
    len.erase(len.find(*r - *l));
    len.insert(*r - x);
    len.insert(x - *l);
    s.insert(x);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> w >> h >> n;
    multiset <int> lenx, leny;
    lenx.insert(w); leny.insert(h);
    set <int> rx, ry;
    rx.insert(0); rx.insert(w); 
    ry.insert(0); ry.insert(h);
    for (int i = 0; i < n; ++i) {
        char t;
        int x;
        cin >> t >> x;
        if (t == 'V') {
            upd(rx, lenx, x);
        }
        else {
            upd(ry, leny, x);
        }
        cout << *lenx.rbegin() * *leny.rbegin() << '\n';
    }   
}