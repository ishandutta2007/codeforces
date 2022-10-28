#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
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
    vector<pair<ll,ll>> seq(n);
    for(auto &[x,y] : seq){
        cin >> x >> y;
    }
    vector<int> ans;
    ans.push_back(1);
    vector<bool> vis(n);
    vis[0] = 1;
    auto best = [&](int idx){
        auto &[x1,y1] = seq[idx-1];
        ll bd = 0, bidx;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            auto &[x2,y2] = seq[i];
            if(bd < (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)){
                bd = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                bidx = i + 1;
            }
        }
        return bidx;
    };
    while(ans.size() < n){
        int nxt = best(ans.back());
        vis[nxt-1] = 1;
        ans.push_back(nxt);
    }
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}