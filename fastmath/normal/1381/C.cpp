#include<bits/stdc++.h>
using namespace std;
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

//dont use exit(0) !
void solve() {
    int n, x, y;

    cin >> n >> x >> y;

    vector <int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    
    vector <bool> used(n + 2);
    for (auto e : b)
        used[e] = 1;

    int neu = -1;
    for (int i = 1; i <= n + 1; ++i)
        if (!used[i])
            neu = i;
    assert(neu != -1);

    //n - y neutral                
    //x - equal

    vector <vector <int> > pos(n + 2);
    vector <int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        pos[b[i]].app(i);
    }   

    set <ii> ms;
    for (int i = 1; i <= n + 1; ++i) {
        if (i != neu) {
            ms.insert(mp(pos[i].size(), i));
        }
    }   

    for (int t = 0; t < x; ++t) {
        int x = ms.rbegin()->s;
        assert(pos[x].size());
        ans[pos[x].back()] = x;

        ms.erase(mp(pos[x].size(), x));
        pos[x].pop_back();
        ms.insert(mp(pos[x].size(), x));
    }   

    vector <int> pot(n + 2);
    for (int i = 1; i <= n + 1; ++i) {
        pot[i] = pos[i].size();
    }   

    for (int t = 0; t < n - y; ++t) {
        int x = ms.rbegin()->s;
        assert(pos[x].size());
        ans[pos[x].back()] = neu;

        ms.erase(mp(pos[x].size(), x));
        pos[x].pop_back();
        ms.insert(mp(pos[x].size(), x));
    }   

    ms.clear();
    vector <int> cnt(n + 2);
    for (int i = 1; i <= n + 1; ++i) {
        if (i != neu) {
            cnt[i] = pos[i].size();

            //cout << "cnt " << i << ' ' << cnt[i] << endl;

            ms.insert(mp(cnt[i], i));
        }
    }

    int ost = y - x;

    //debug(ost);


    for (int t = 0; t < ost; ++t) {

        while (ms.size() && pot[ms.begin()->s] == 0) {
            ms.erase(ms.begin());
        }   

        if (ms.empty()) {
            cout << "NO" << endl;
            return;
        }   

        int x = ms.begin()->s;
        ms.erase(ms.begin());
        if (cnt[x] + 1 > ost) {
            cout << "NO" << endl;
            return;
        }   
        ++cnt[x];
        --pot[x];
        ms.insert(mp(cnt[x], x));
    }   

    /*
    for (int i = 1; i <= n + 1; ++i) {
        cout << i << " : " << cnt[i] << endl;
    }
    */

    vector <int> p;
    for (int i = 0; i < n; ++i) {
        if (ans[i] == -1) {
            p.app(i);
        }   
    }   

    ms.clear();
    vector <int> ost1(n + 2);
    for (int i = 1; i <= n + 1; ++i) {  
        if (cnt[i] > pos[i].size()) {
            ms.insert(mp(cnt[i], i));
            ost1[i] = cnt[i] - pos[i].size();
        }   
    }

    for (int i : p) {
        /*        
        cout << "ms : ";
        for (auto e : ms)
            cout << "(" << e.f << ' ' << e.s << ") ";
        cout << endl;
        */

        assert(ms.size());

        int x = -1;
        auto t = prev(ms.end());
        if (t->s != b[i]) {
            x = t->s;
        }   
        else {
            assert(ms.size() > 1);
            x = prev(t)->s;
        }   

        ms.erase(mp(cnt[x], x));
        ms.erase(mp(cnt[b[i]], b[i]));

        --cnt[x];
        --cnt[b[i]];
        --ost1[x];
        ans[i] = x;

        //debug(i);
        //debug(x);

        if (ost1[x]) {
            ms.insert(mp(cnt[x], x));
        }
        if (ost1[b[i]]) {
            ms.insert(mp(cnt[b[i]], b[i]));
        }
    }   

    cout << "YES" << endl;

    int resx = 0;
    for (int i = 0; i < n; ++i)
        resx += ans[i] == b[i];
    if (resx != x) {
        cout << "LMAO x" << endl;
    }       

    for (auto e : ans) {
        if (e < 1 || e > n + 1) {
            cout << "LMAO" << endl;
        }   
    }   

    vector <int> cnt1(n+2), cnt2(n+2);
    for (auto e : ans)
        ++cnt1[e];
    for (auto e : b)
        ++cnt2[e];
    int resy = 0;
    for (int i = 1; i <= n + 1; ++i)
        resy += min(cnt1[i], cnt2[i]);
    if (resy != y) {
        cout << "LMAO y" << endl;
    }               
    for (auto e : ans)
        cout << e << ' ';
    cout << endl;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    while (t--)
        solve();

}