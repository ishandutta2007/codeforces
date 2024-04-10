/**
 *    author:  gary
 *    created: 30.09.2022 22:32:01
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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
bool vis[1001];
int deg[1001];
int id[1001];
int ans[1000];
bool cmp(int a,int b){return deg[a]>deg[b];}
using namespace atcoder;
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        rb(i,1,n) cin>>deg[i],vis[i]=0,id[i]=i;
        sort(id+1,id+1+n,cmp);
        dsu graph(n);
        rb(i_,1,n){
            int i=id[i_];
            // cerr<<i<<endl;
            if(!vis[i]&&deg[i]>1){
                vis[i]=1;
                rb(j,1,deg[i]){
                    int ret;
                    cout<<"? "<<i<<endl;fflush(stdout);
                    cin>>ret;
                    graph.merge(i-1,ret-1);
                    if(vis[ret]){
                        break;
                    }
                    vis[ret]=1;
                }
            }
        }
        auto temp=graph.groups();
        rep(i,temp.size()) for(auto x:temp[i]) ans[x]=i+1;
        cout<<"! ";
        rep(i,n) cout<<ans[i]<<" ";
        cout<<endl;
        fflush(stdout);
    }
    
    return 0;
}