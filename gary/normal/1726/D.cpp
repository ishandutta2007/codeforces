/**
 *    author:  gary
 *    created: 06.09.2022 22:26:18
**/
#include<bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
using namespace atcoder;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
SRAND;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<mp> edges;
    vector<mp> old;
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        edges.emplace_back(u,v);
    }
    old=edges;
    set<mp> temp;
    while (true){
        shuffle(ALL(edges),rng);
        dsu graph(n+1);
        set<int> se;
        vector<mp> orz;
        for(auto &[u,v]:edges){
            if(graph.same(u,v)){
                orz.emplace_back(u,v);
                se.insert(u);
                se.insert(v);
            }
            else graph.merge(u,v);
        }
        if(m!=n+2||se.size()!=3) {for(auto it:orz) temp.insert(it);break;}
    }
    for(auto it:old){
        cout<<temp.count(it);
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}