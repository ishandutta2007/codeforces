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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int l1[N], r1[N], l2[N], r2[N];
struct Event {
    bool add;
    int x, i;
};  
bool comp1(Event a, Event b) {
    return a.x < b.x || (a.x == b.x && a.add > b.add);
}
bool comp2(Event a, Event b) {
    return a.x > b.x || (a.x == b.x && a.add > b.add);
}
bool check(set <int> &p, int l, int r) {
    auto t = p.lower_bound(l);
    return t != p.end() && *t <= r;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
    for (int t = 0; t < 2; ++t) {
        
        {
        vector <Event> a;
        for (int i = 0; i < n; ++i) {
            a.app({1, l1[i], i});
            a.app({0, r1[i], i});
        }   
        sort(all(a), comp1);
        set <int> p;
        for (auto e : a) {
            if (e.add) {
                if (check(p, l2[e.i], r2[e.i])) {
                    cout << "NO\n";
                    exit(0);
                }   
            }   
            else {
                p.insert(l2[e.i]);
                p.insert(r2[e.i]);
            }   
        }
        }

        {
        vector <Event> a;
        for (int i = 0; i < n; ++i) {
            a.app({1, r1[i], i});
            a.app({0, l1[i], i});
        }   
        sort(all(a), comp2);
        set <int> p;
        for (auto e : a) {
            if (e.add) {
                if (check(p, l2[e.i], r2[e.i])) {
                    cout << "NO\n";
                    exit(0);
                }   
            }   
            else {
                p.insert(l2[e.i]);
                p.insert(r2[e.i]);
            }   
        }
        }

        for (int i = 0; i < n; ++i) {
            swap(l1[i], l2[i]);
            swap(r1[i], r2[i]);
        }   
    }

    cout << "YES\n";
}