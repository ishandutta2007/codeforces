#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 5e5+7;
vector <int> d[N];

int n;
vector <ii> ans;

void twice(int a, int b) { //twice a by b
    assert(d[a].size() && d[b].size());
    assert(d[a].size() <= d[b].size());
    int sz = d[a].size();
    for (int i = 0; i < sz; ++i) {
        ans.app(mp(d[a][i], d[b].back()));        
        d[a].app(d[b].back());
        d[b].pop_back();
    }   
}   

int get(int l, int r) {
    if (l == r)
        return l;

    assert((r - l + 1) % 2 == 0);        
    int m = (l + r) >> 1;
    int L = get(l, m);
    int R = get(m + 1, r);
    twice(L, R);
    return L;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    cin >> n;
    for (int i = 1; i <= n; ++i)
        d[i] = {i};

    int ptr = 1;
    vector <int> c;
    for (int bit = 20; bit >= 0; --bit) {
        if ((n >> bit) & 1) {
            c.app(get(ptr, ptr + (1 << bit) - 1));
            ptr += 1 << bit;                        
        }   
    }   

    while (c.size() > 2) {
        int sz = c.size();
        while (d[c[sz - 1]].size() < d[c[sz - 2]].size()) {
            twice(c[sz - 1], c[0]);
        }   
        assert(d[c[sz - 1]].size() == d[c[sz - 2]].size());
        twice(c[sz - 2], c[sz - 1]);
        c.pop_back();
    }   

    assert(ans.size() <= 500 * 1000);

    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e.f << ' ' << e.s << endl;
}