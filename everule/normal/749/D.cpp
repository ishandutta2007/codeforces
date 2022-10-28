#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const T &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const T &vec){
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
    vector<set<int>> bids(n);
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        --a[i];
        bids[a[i]].insert(i);
    }
    set<int> lastbid;
    for(int i=0;i<n;i++){
        if(bids[i].size()) lastbid.insert(*bids[i].rbegin());
    }
    int q;
    cin>>q;
    set<int> init = lastbid;
    while(q--){
        int k;
        cin>>k;
        vector<int> removed(k);
        cin>>removed;
        for(auto &x : removed){
            if(bids[--x].size()) lastbid.erase(*bids[x].rbegin());
        }
        if(lastbid.empty()){
            cout<<"0 0\n";
            for(const auto &x : removed){
                if(bids[x].size()) lastbid.insert(*bids[x].rbegin());
            }
            continue;
        }
        int winner = a[*lastbid.rbegin()];
        lastbid.erase(*bids[winner].rbegin());
        if(lastbid.empty()){
            cout<<winner+1<<" "<<b[*bids[winner].begin()]<<"\n";
            for(const auto &x : removed){
                if(bids[x].size()) lastbid.insert(*bids[x].rbegin());
            }
            lastbid.insert(*bids[winner].rbegin());
            continue;
        }
        int idx = *bids[winner].lower_bound(*lastbid.rbegin());
        cout<<winner+1<<" "<<b[idx]<<"\n";
        for(const auto &x : removed){
            if(bids[x].size()) lastbid.insert(*bids[x].rbegin());
        }
        lastbid.insert(*bids[winner].rbegin());
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    solve();
}