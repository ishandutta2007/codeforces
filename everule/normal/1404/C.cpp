#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
struct query{
    int l,r,idx;
    query(){}
    query(int l,int r,int idx) : l(l), r(r), idx(idx) {}
    bool operator<(const query &o){
        return l<o.l;
    }
};
void solve(){
    int n,Q;
    cin>>n>>Q;
    vector<int> seq(n);
    cin>>seq;
    for(int i=1;i<=n;i++){
        if(seq[i-1]>i){
            seq[i-1] = 1e9;
        }
        else{
            seq[i-1] = i - seq[i-1];
        }
    }
    indexed_set<pair<int,int>> curr;
    vector<vector<int>> off(n+1);
    for(int i=0;i<n;i++){
        if(seq[i]>curr.size()){
            off[0].pb(i);
        }
        else{
            int l = seq[i]!=0 ? (*curr.find_by_order(curr.size() - seq[i])).first : i+1;
            off[l].pb(i);
            curr.insert({l,i});
        }
    }
    vector<query> queries(Q);
    for(int i=0;i<Q;i++){
        cin>>queries[i].l>>queries[i].r;
        queries[i].r = n - 1 - queries[i].r;
        queries[i].idx = i;
    }
    sort(queries.begin(), queries.end());
    vector<int> ans(Q);
    indexed_set<int> on;
    for(int i=0;i<n;i++){
        on.insert(i);
    }
    for(int i=0,j=0;i<n;i++){
        for(const auto &idx : off[i]){
            on.erase(idx);
        }
        while(j<Q && queries[j].l==i){
            ans[queries[j].idx] = on.order_of_key(queries[j].r + 1);
            ++j;
        }
    }
    for(const auto &x : ans){
        cout<<x<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}