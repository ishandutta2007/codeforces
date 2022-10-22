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

const int LG = 50;
int d[LG];

bool win() {
    return d[0];
}   

struct Out {
    int a;
    char t;
    int b;
};  
vector <Out> ans;

bool want(int x) {
    for (int bit = LG - 1; bit >= 0; --bit) {
        if ((x >> bit) & 1) {
            if (!d[bit]) {
                return 1;
                break;
            }              
            else {
                x ^= d[bit];
            }   
        }   
    }   
    return 0;
}   


void add(int x) {
    vector <Out> cur;
    for (int bit = LG - 1; bit >= 0; --bit) {
        if ((x >> bit) & 1) {
            if (!d[bit]) {
                d[bit] = x;
                for (auto e : cur)
                    ans.app(e);
                break;
            }              
            else {
                cur.app({d[bit], '^', x});
                x ^= d[bit];
            }   
        }   
    }   
}   

int max_op = 0;
void solve(int x) {
    memset(d, 0, sizeof d);
    ans.clear();
    add(x);

    while (!win()) {
        bool did = 0;
        for (int i = 0; i < LG && !win(); ++i) {
            for (int j = 0; j < LG && !win(); ++j) {
                if (d[i] && d[j] && d[i] + d[j] < (1ll << LG)) {
                    if (want(d[i] + d[j])) {
                        ans.app({d[i], '+', d[j]});
                        add(d[i] + d[j]);
                        did = 1;
                    }   
                }   
            }   
        }   
        assert(did);
    }   

    max_op = max(max_op, (int)ans.size());
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e.a << ' ' << e.t << ' ' << e.b << endl;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int n;
    cin >> n;
    solve(n);
    
    /*
    for (int x = 900001; x < 1000 * 1000; x += 2) {
        solve(x);
    }   
    debug(max_op);
    */
}