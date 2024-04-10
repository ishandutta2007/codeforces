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
    vector<int> p(n);
    cin>>p;
    for(auto &x : p) --x;
    vector<int> color(n, -1);
    int cycles = 0;
    for(int i=0;i<n;i++){
        if(color[i] != -1) continue;
        color[i] = cycles;
        int u = i;
        while(p[u] != i){
            u = p[u];
            color[u] = cycles;
        }
        ++cycles;
    }
    vector<int> ans;
    vector<bool> vis(n);
    {
        ans.push_back(0);
        int u = 0;
        vis[0] = 1;
        while(p[u] != 0){
            u = p[u];
            vis[u] = 1;
            ans.push_back(u);
        }
    }
    while(ans.size() < n){
        for(int i=0;i<ans.size();i++){
            int x = p[ans[i]];
            if(x > 0 && !vis[x-1]){
                int u = x-1;
                int pos = i + 1;
                ans.insert(ans.begin() + pos++, u);
                vis[u] = 1;
                while(p[u] != x-1){
                    u = p[u];
                    vis[u] = 1;
                    ans.insert(ans.begin() + pos++, u);
                }
                break;
            }
            if(x + 1 < n && !vis[x+1]){
                int u = x+1;
                int pos = i + 1;
                ans.insert(ans.begin() + pos++, u);
                vis[u] = 1;
                while(p[u] != x+1){
                    u = p[u];
                    vis[u] = 1;
                    ans.insert(ans.begin() + pos++, u);
                }
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto &x : ans) ++x;
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}