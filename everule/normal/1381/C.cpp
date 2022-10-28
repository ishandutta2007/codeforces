#include <iostream>
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
int MEX(vector<int> &x){
    vector<bool> found(x.size());
    for(int i=0;i<x.size();i++){
        if(x[i]<x.size()){
            found[x[i]]=1;
        }
    }
    for(int i=0;i<x.size();i++){
        if(!found[i]){
            return i;
        }
    }
    return x.size();
}
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> seq(n);
    cin>>seq;
    for(auto &x : seq) --x;
    vector<int> save = seq;
    sort(seq.begin(), seq.end());
    const int free = MEX(seq);
    set<pair<int,int>> sortcount;
    vector<int> count(n+1);
    for(const auto &x : seq) ++count[x];
    for(int i=0;i<=n;i++){
        sortcount.insert({count[i], i});
    }
    map<int, vector<int>> ans;
    for(int i=0;i<x;i++){
        auto it = *(--sortcount.end());
        sortcount.erase(it);
        --it.first;
        sortcount.insert(it);
        ans[it.second].pb(it.second);
    }
    int left = n - x;
    int mxcount = (*--sortcount.end()).first;
    int mxval = (*--sortcount.end()).second;
    int totfree = n - y;
    while(mxcount > left/2){
        --totfree;
        if(totfree<0){
            cout<<"NO\n";
            return;
        }
        auto it = *(--sortcount.end());
        sortcount.erase(it);
        --it.first;
        sortcount.insert(it);
        ans[mxval].pb(free);
        --left;
        --mxcount;
    }
    vector<int> helper;
    int offset = 0;
    for(const auto &x : sortcount){
        offset = max(offset, x.first);
        for(int i=0;i<x.first;i++){
            helper.pb(x.second);
        }
    }
    for(int i=0;i<helper.size();i++){
        int curr = helper[(i+offset)%(helper.size())];
        if(curr == helper[i]){
            cout<<"F\n";
            return;
        }
        if(totfree) ans[helper[i]].pb(free),--totfree;
        else ans[helper[i]].pb(curr);
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++){
        cout<<ans[save[i]].back() + 1<<" ";
        ans[save[i]].pop_back();
    }
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