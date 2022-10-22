#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int N, M;
set<pair<int, int>> conn[MAXN];
set<tuple<int, int, int> > Imps;
map<pair<int, int>, int> MM;
map<long long, int> d3;

void remd3(int a)
{
    if(conn[a].size() < 3) return;
    auto it = conn[a].begin();
    long long ans = 0;
    for(int i=0; i<3; ++i) ans += (it++)->first;
    auto it2 = d3.find(ans);
    if(it2->second == 1) d3.erase(it2); else it2->second--;
}
void insd3(int a)
{
    if(conn[a].size() < 3) return;
    auto it = conn[a].begin();
    long long ans = 0;
    for(int i=0; i<3; ++i) ans += (it++)->first;
    // cout << "!" << a << " " << ans << endl;
    auto it2 = d3.find(ans);
    d3[ans]++;
}

void remf4(int a)
{
    auto it = conn[a].begin();
    for(int i=0; i<min(4, (int)conn[a].size()); ++i)
    {
        auto [w, u] = *(it++);
        Imps.erase({w, min(u, a), max(u, a)});
    }
}

bool einf4(int a, int w, int b)
{
    auto it = conn[a].begin();
    for(int i=0; i<min(4, (int) conn[a].size()); ++i)
        if(make_pair(w, b) == *(it++)) return true;
    return false;
}

void insf4(int a)
{
    auto it = conn[a].begin();
    for(int i=0; i<min(4, (int)conn[a].size()); ++i)
    {
        auto [w, u] = *(it++);
        if(einf4(u, w, a)) Imps.insert({w, min(u, a), max(u, a)});
    }
}


void add(int x, int y, int w)
{
    if(x > y) swap(x, y);
    remd3(x); remd3(y);
    remf4(x); remf4(y);
    conn[x].emplace(w, y); conn[y].emplace(w, x); MM[{x, y}] = w;
    insf4(x); insf4(y);
    insd3(x); insd3(y);
}
void rem(int x, int y)
{
    if(x > y) swap(x, y);
    int w = MM[{x, y}];
    remd3(x); remd3(y);
    remf4(x); remf4(y);
    conn[x].erase({w, y}); conn[y].erase({w, x});
    insf4(x); insf4(y);
    insd3(x); insd3(y);
}
long long solve()
{
    // for(auto [a, b]: d3) cout << a << " " << b << endl;
    // cout << "==" <<endl;
    auto iti = Imps.begin();
    long long ans = 1e10;
    if(!d3.empty()) ans = min(ans, d3.begin()->first);
    for(int i=0; i<3; ++i)
    {
        auto [w, x, y] = *(iti++);
        for(auto [ww, xx, yy]: Imps)
            if(x != xx && x != yy && y != xx && y != yy)
            {
                ans = min(ans, (long long)w+ww);
                break;
            }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    vector<tuple<int, int, int> > V;
    for(int i=0; i<M; ++i)
    {
        int u, v, w; cin >> u >> v >> w;
        add(u-1, v-1, w);
    }
    cout << solve() << '\n';
    int Q; cin >> Q;
    for(int i=0; i<Q; ++i)
    {
        int T; cin >> T;
        if(T == 0)
        {
            int u, v; cin >> u >> v;
            rem(u-1, v-1);
        }
        else
        {
            int u, v, w; cin >> u >> v >> w;
            add(u-1, v-1, w);
        }
        cout << solve() << '\n';
    }
    return 0;
}