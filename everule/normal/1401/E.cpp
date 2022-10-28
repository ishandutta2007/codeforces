#include <iostream>
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long int;
template<typename T>
using indexed_set  = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
const int MAXC = 1e6;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> left;
    vector<pair<int,int>> right;
    ll ans = 1;
    for(int i=0;i<n;i++){
        int y,l,r;
        cin>>y>>l>>r;
        if(l==0 && r==MAXC){
            ++ans;
        }
        if(l==0){
            left.pb({y,r});
        }    
        else{
            right.pb({y,l});
        }
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    vector<pair<int,int>> up, down;
    for(int i=0;i<m;i++){
        int x,d,u;
        cin>>x>>d>>u;
        if(d==0 && u==MAXC){
            ++ans;
        }
        if(d==0){
            down.pb({u,x});
        }
        else{
            up.pb({d,x});
        }
    }
    sort(down.begin(), down.end());
    sort(up.begin(), up.end(), greater<pair<int,int>>());
    indexed_set<pair<int,int>> currleft;
    indexed_set<pair<int,int>> currright;
    int idxl = 0;
    int idxr = 0;
    for(const auto &[y,x] : down){
        while(idxl < (int)left.size() && left[idxl].first <= y){
            currleft.insert({left[idxl].second, idxl});
            ++idxl;
        }
        while(idxr < (int)right.size() && right[idxr].first <= y){
            currright.insert({right[idxr].second, idxr});
            ++idxr;
        }
        ans+=currleft.size() - currleft.order_of_key({x,-1});
        ans+=currright.order_of_key({x,1e9});
    }
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());
    idxl = 0;
    idxr = 0;
    currleft.clear();
    currright.clear();
    for(const auto &[y,x] : up){
        while(idxl < left.size() && left[idxl].first >= y){
            currleft.insert({left[idxl].second,idxl});
            ++idxl;
        }
        while(idxr < right.size() && right[idxr].first >= y){
            currright.insert({right[idxr].second,idxr});
            ++idxr;
        }
        ans+=currleft.size() - currleft.order_of_key({x,-1});
        ans+=currright.order_of_key({x,1e9});
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}