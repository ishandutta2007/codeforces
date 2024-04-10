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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> island(n), bridge(m);
    vector<pair<pair<ll,ll>, ll>> needed(n-1);
    for(auto &isle : island){
        cin>>isle.first>>isle.second;
    }
    for(int i=0;i<m;i++){
        cin>>bridge[i].first;
        bridge[i].second = i+1;
    }
    sort(bridge.begin(), bridge.end());
    for(int i=0;i<n-1;i++){
        needed[i].first.first = island[i+1].first - island[i].second;
        needed[i].first.second = island[i+1].second - island[i].first;
        needed[i].second = i;
    }
    set<pair<ll,ll>> curr;
    sort(needed.begin(), needed.end());
    vector<int> ans(n-1, -1);
    for(int i=0, j=0;i<m;i++){
        while(j<n-1 && needed[j].first.first <= bridge[i].first){
            curr.insert({needed[j].first.second, needed[j].second});
            ++j;
        }
        if(curr.empty()){
            continue;
        }
        if((*curr.begin()).first < bridge[i].first){
            cout<<"No";
            return;
        }
        ans[(*curr.begin()).second] = bridge[i].second;
        curr.erase(curr.begin());
    }
    for(const auto &val : ans){
        if(val==-1){
            cout<<"No";
            return;
        }
    }
    cout<<"Yes\n";
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}