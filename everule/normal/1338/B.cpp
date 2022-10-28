#include <bits/stdc++.h>
using std::cin, std::cout;
using std::ostream, std::istream;
using std::vector;
using std::set, std::multiset;
using std::map, std::multimap;
using std::priority_queue;
using std::string;
using std::array;
using std::function;
using namespace std::ranges;
using ll = long long int;
template <typename T>
concept iterable_container = requires (T x) {
    x.begin();
    x.end();
};
template<typename T> requires iterable_container<T> and (not std::is_same_v<T, std::string>)
ostream& operator<<(ostream &out,const T& seq){
    for(const auto &x : seq){
        out<<x;
        if constexpr(!iterable_container<decltype(x)>) out<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T> requires iterable_container<T> and (not std::is_same_v<T, std::string>)
istream& operator>>(istream& in, T& seq){
    for(auto &x : seq){
        in>>x;
    }
    return in;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n == 2){
        cout<<"1 1\n";
        return;
    }
    vector<int> dep(n);
    int mx = 0;
    array<bool, 2> pr = {0,0};
    int r = 0;
    while(g[r].size() == 1) r++;
    function<void(int,int)> dfs = [&](int u,int p){
        int cnt = 0;
        for(auto &v : g[u]){
            if(v == p) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
            if(g[v].size() == 1) cnt++;
        }
        mx += g[u].size() - max(cnt-1, 0) - (u != r);
        if(g[u].size() == 1) pr[dep[u] % 2] = 1;
    };
    dfs(r, -1);
    cout<<2 * (pr[0] + pr[1]) - 1<<" "<<mx<<"\n";
}
int main(){
    int t = 1;
    //cin>>t;
    while(t--) solve();
}