#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> tour, time;
    {
        function<void(int,int,int)> dfs = [&](int u,int pr, int c_time){
            tour.push_back(u);
            time.push_back(c_time);
            bool need_reduce = 1;
            if(u != 0 && need_reduce && c_time >= g[u].size()){
                c_time -= g[u].size();
                tour.push_back(u);
                time.push_back(c_time);
                need_reduce = 0;
            }
            for(auto &v : g[u]){
                if(v == pr) continue;
                dfs(v, u, c_time + 1);
                c_time++;
                tour.push_back(u);
                time.push_back(c_time);
                if(u != 0 && need_reduce && c_time >= g[u].size()){
                    c_time -= g[u].size();
                    tour.push_back(u);
                    time.push_back(c_time);
                    need_reduce = 0;
                }
            }
        };
        dfs(0, 0, 0);
    }
    cout<<tour.size()<<"\n";
    for(int i=0;i<tour.size();i++){
        cout<<tour[i]+1<<" "<<time[i]<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}