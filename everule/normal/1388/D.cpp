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
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    cin>>a>>b;
    vector<set<int>> adj(n), adjback(n);
    for(int i=0;i<n;i++){
        if(b[i]==-1){
            continue;
        }
        adjback[b[i]-1].insert(i);
        adj[i].insert(b[i]-1);
    }
    ll ans = 0;
    deque<int> order;
    deque<int> order2;
    vector<pair<int,int>> toerase;
    function<ll(int)> dfsback = [&](int u){
        ll push = a[u];
        for(const auto &v : adjback[u]){
            ll curr = dfsback(v);
            if(curr>=0){
                push+=curr;
            }
            else{
                toerase.pb({u,v});
                order2.push_front(v);
            }
        }
        ans+=push;
        return push;
    };
    for(int i=0;i<n;i++){
        if(adj[i].size()==0){
            order.push_front(i);
            dfsback(i);
        }
    }
    for(const auto &x : toerase){
        adjback[x.first].erase(x.second);
    }
    vector<int> seq;
    seq.reserve(n);
    function<void(int, vector<int>&)> getorder = [&](int u, vector<int> &curr){
        curr.pb(u);
        for(const auto &x : adjback[u]){
            getorder(x, curr);
        }
    };
    for(const auto &u : order){
        vector<int> curr;
        getorder(u, curr);
        reverse(curr.begin(), curr.end());
        for(const auto &x : curr){
            seq.pb(x+1);
        }
    }
    for(const auto &u : order2){
        vector<int> curr;
        getorder(u, curr);
        reverse(curr.begin(), curr.end());
        for(const auto &x : curr){
            seq.pb(x+1);
        }
    }
    cout<<ans<<"\n";
    cout+seq;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}