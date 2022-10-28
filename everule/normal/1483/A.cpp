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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> f(m);
    vector<int> cnt(n);
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        f[i].resize(k);
        cin>>f[i];
        for(auto &v : f[i]) --v;
    }
    vector<int> _(m);
    iota(_.begin(), _.end(), 0);
    sort(_.begin(), _.end(), [&](int x,int y){
        return f[x].size() < f[y].size();
    });
    vector<int> ans(m);
    for(auto &i : _){
        if(f[i].size() == 1){
            ans[i] = f[i][0];
            cnt[ans[i]]++;
            continue;
        }
        if(cnt[f[i][0]] < cnt[f[i][1]]){
            ans[i] = f[i][0];
        }
        else{
            ans[i] = f[i][1];
        }
        cnt[ans[i]]++;
    }
    if(*max_element(cnt.begin(), cnt.end()) > (m + 1) / 2){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(auto &x : ans) cout<<x+1<<" ";
    cout<<"\n";
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