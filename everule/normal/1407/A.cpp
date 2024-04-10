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
pair<int,int> operator+(const pair<int,int> &x, const pair<int,int> &y){
    return mp(x.first + y.first, x.second);
}
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    const int offset = n/2 + 1;
    vector<vector<pair<int,int>>> dpodd(n+1, vector<pair<int,int>>(n+3, {-1e9,-1}));
    vector<vector<pair<int,int>>> dpeven(n+1, vector<pair<int,int>>(n+3, {-1e9, -1}));
    vector<pair<int,int>> bestodd(n+3, {-1e9,-1}), besteven(n+3, {-1e9, -1});
    dpeven[0][offset] = {0,-1};
    besteven[offset] = {0,-1};
    for(int i=1;i<=n;i++){
        vector<pair<int,int>> nextodd(n+3, {-1e9, -1}), nexteven(n+3, {-1e9, -1});
        for(int j=1;j<n+2;j++){
            dpodd[i][j] = besteven[j-seq[i-1]] + mp(1,i);
            nextodd[j] = max(bestodd[j], {dpodd[i][j].first, i});
            dpeven[i][j] = bestodd[j+seq[i-1]] + mp(1,i);
            nexteven[j] = max(besteven[j], {dpeven[i][j].first, i});
        }
        swap(besteven, nexteven);
        swap(bestodd, nextodd);
    }
    cout<<"\n";
    int sign = -1;
    if(besteven[offset]>bestodd[offset]){
        swap(besteven, bestodd);
        swap(dpeven, dpodd);
        sign*=-1;
    }
    int idx = bestodd[offset].second;
    int sum = offset;
    vector<int> ans;
    ans.pb(seq[idx-1]);
    while(~dpodd[idx][sum].second){
        sum+=(seq[idx-1] ? sign : 0);
        idx = dpodd[idx][sum - (seq[idx-1] ? sign : 0)].second;
        sign*=-1;
        ans.pb(seq[idx-1]);
        swap(dpeven,dpodd);
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(const auto &x : ans){
        cout<<x<<" ";
    }
    cout<<'\n';
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