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
    /*
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    */
    auto query = [&](vector<int> s){
        /*cout+s;
        int ans = 0;
        for(auto &x : s){
            for(auto &y : s){
                ans += g[x][y];
            }
        }
        return ans / 2;
        */
       if(s.size() == 0) return 0;
        cout<<"? "<<s.size()<<"\n";
        for(auto &x : s) cout<<x+1<<" ";
        cout<<endl;
        int ans;
        cin>>ans;
        return ans;
    };
    auto edge_between = [&](int u, vector<int> s){
        s.push_back(u);
        int num_edge = query(s);
        s.pop_back();
        num_edge -= query(s);   
        return num_edge;
    };
    auto find_edge = [&](int u, vector<int> s){
        int l = 0, r = s.size();
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(edge_between(u, vector<int>(s.begin() + l, s.begin() + mid))){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        return s[l];
    };
    int n;
    cin>>n;
    vector<bool> vis(n);
    vis[0] = 1;
    vector<bool> col(n);
    queue<int> bfs;
    bfs.push(0);
    vector<int> par(n);
    vector<int> dep(n);
    while(bfs.size()){
        int u = bfs.front();
        bfs.pop();
        vector<int> to_query;
        for(int i=0;i<n;i++){
            if(!vis[i]) to_query.push_back(i);
        }
        while(edge_between(u, to_query)){
            int v = find_edge(u, to_query);
            vis[v] = 1;
            to_query.erase(find(to_query.begin(), to_query.end(), v));
            bfs.push(v);
            col[v] = !col[u];
            par[v] = u;
            dep[v] = dep[u] + 1;
        }
    }
    //cout+par+dep;
    vector<int> left, right;
    for(int u=0;u<n;u++) if(col[u]) left.push_back(u); else right.push_back(u);
    int left_in_edge = query(left);
    int right_in_edge = query(right);
    if(left_in_edge == 0 && right_in_edge == 0){
        cout<<"Y "<<left.size()<<"\n";
        for(auto &x : left) cout<<x+1<<" ";
        cout<<endl;
        return;
    }
    vector<int> bad = (left_in_edge > 0 ? left : right);
    array<int, 2> bad_edge = {-1, -1};
    for(int i=1;i<bad.size();i++){
        if(edge_between(bad[i], vector<int>(bad.begin(), bad.begin() + i))){
            bad_edge = array<int, 2>({bad[i], find_edge(bad[i], vector<int>(bad.begin(), bad.begin() + i))});
        }
    }
    //cout<<bad_edge[1]<<" "<<bad_edge[0]<<"...\n";
    //cout.flush();
    vector<int> left_path = {bad_edge[0]}, right_path = {bad_edge[1]};
    while(dep[left_path.back()] > 0){
        left_path.push_back(par[left_path.back()]);
    }
    while(dep[right_path.back()] > 0){
        right_path.push_back(par[right_path.back()]);
    }
    while(left_path.back() == right_path.back()){
        left_path.pop_back();
        right_path.pop_back();
    }
    left_path.push_back(par[left_path.back()]);
    vector<int> tot_path = left_path;
    while(right_path.size()){
        tot_path.push_back(right_path.back());
        right_path.pop_back();
    }
    assert(tot_path.size() % 2 == 1);
    cout<<"N "<<tot_path.size()<<"\n";
    for(auto &x : tot_path) cout<<x+1<<" ";
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}