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
    ll val = 1;
    ll last = 1;
    vector<int> ans;
    ans.pb(1);
    while(val<n){
        if(val  + 2*last<=n){
            ans.pb(2*last);
            last = 2*last;
            val+=last;
            continue;
        }
        if(val + last<=n){
            ans.pb(n-val);
            break;
        }
        val-=last;
        int extra = n - val;
        ans.pop_back();
        last=extra/2;
        ans.pb(last);
        ans.pb(extra&1 ? last+1 : last);
        break;
    }
    //cout+ans;
    cout<<ans.size() - 1<<"\n";
    for(int i=1;i<ans.size();i++){
        cout<<ans[i]-ans[i-1]<<" ";
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