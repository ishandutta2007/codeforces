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
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    cin>>a;
    vector<array<int, 2>> b(m);
    for(auto &[x,y] : b) cin>>x>>y;
    vector<int> sa = a;
    sort(sa.begin(), sa.end());
    sa.resize(unique(sa.begin(), sa.end()) - sa.begin());
    for(auto &x : a) x = lower_bound(sa.begin(), sa.end(), x) - sa.begin();
    for(auto &[x,y] : b) x = lower_bound(sa.begin(), sa.end(), x) - sa.begin();
    for(auto &[y,x] : b) x = lower_bound(sa.begin(), sa.end(), x) - sa.begin();
    //cout+a;
    vector<vector<int>> co(n+1);
    vector<int> c(n);
    for(auto &x : a){
        c[x]++;
    }
    for(int i=0;i<n;i++){
        if(c[i] > 0) co[c[i]].push_back(i);
    }
    map<array<int, 2>, vector<array<int, 2>>> bd;
    for(auto [x,y] : b){
        if(c[x] > c[y]) swap(x, y);
        bd[{c[x], c[y]}].push_back({x,y});
        if(c[x] == c[y]) bd[{c[x], c[y]}].push_back({y,x});
    }
    for(auto &[x,y] : bd){
        sort(y.begin(), y.end(), greater<array<int, 2>>());
    }
    for(int i=0;i<=n;i++) sort(co[i].begin(), co[i].end(), greater<int>());
    vector<int> pc;
    for(int i=0;i<=n;i++){
        if(co[i].size() > 0){
            pc.push_back(i);            
        }
    }
    /*for(auto &[x,y] : bd){
        cout<<x[0]<<" "<<x[1]<<"\n";
        for(auto &[b1,b2] : y){
            cout<<b1<<" "<<b2<<"\n";
        }
        cout<<"\n";
    }*/
    ll ans = 0;
    for(int l1=0;l1<pc.size();l1++){
        for(int l2=l1;l2<pc.size();l2++){    
            auto v1 = co[pc[l1]];
            auto v2 = co[pc[l2]];
            int s1 = v1.size();
            int s2 = v2.size();
            auto vb = bd[{pc[l1], pc[l2]}];
            int j = 0;
            for(int i=0;i<v1.size();i++){
                int k = -1;
                do{ 
                    ++k;
                    if(v1[i] == v2[k]) k++;
                    while(k < v2.size() && j < vb.size() && array<int, 2>({v1[i], v2[k]}) < vb[j]){
                        j++;
                    }
                }while(k + 1 < v2.size() && j < vb.size() && vb[j] == array<int, 2>({v1[i], v2[k]}));
                if(k == v2.size()) continue;
                if(j == vb.size() || vb[j] != array<int, 2>({v1[i], v2[k]})) ans = max(ans, 1ll * (pc[l1] + pc[l2]) * (sa[v1[i]] + sa[v2[k]]));
                //cout<<sa[v1[i]]<<" "<<sa[v2[k]]<<" "<<ans<<"\n";
            }
        }
    }
    cout<<ans<<"\n";
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