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
    set<int> add;
    set<int> tobuy;
    vector<int> buys(n);
    vector<int> num(2*n);
    for(int i=0;i<2*n;i++){
        char type;
        cin>>type;
        if(type=='+'){
            add.insert(i);
            num[i] = add.size();
        }
        else{
            int cst;
            cin>>cst;
            --cst;
            buys[cst] = i;
            tobuy.insert(i);
        }
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        auto it = add.lower_bound(buys[i]);
        if(it==add.begin()){
            cout<<"NO\n";
            return;
        }
        int x = *(--it);
        int nxt = *tobuy.lower_bound(x);
        if(nxt!=buys[i]){
            cout<<"NO\n";
            return;
        }
        add.erase(x);
        tobuy.erase(buys[i]);
        ans[num[x]-1] = i+1;
    }
    cout<<"YES\n";
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}