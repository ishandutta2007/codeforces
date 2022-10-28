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
    ll w;
    cin>>w;
    vector<pair<ll,int>> seq(n);
    for(int i=0;i<n;i++){
        cin>>seq[i].first;
        seq[i].second = i;
    }
    sort(seq.begin(), seq.end());
    while(seq.size()!= 0 && seq.back().first > w){
        seq.pop_back();
    }
    n = seq.size();
    if(n == 0){
        cout<<"-1\n";
        return;
    }
    if(seq.back().first >= (w+1)/2){
        cout<<"1\n";
        cout<<seq.back().second + 1<<"\n";
        return;
    }
    ll sum = 0;
    for(const auto &[val,idx] : seq) sum += val;
    if(sum < (w+1)/2){
        cout<<"-1\n";
        return;
    }
    reverse(seq.begin(), seq.end()); // why ?
    vector<int> ans;
    ll wt = 0;
    for(const auto &[val,idx] : seq){
        if(wt >= (w+1)/2) break;
        wt += val;
        ans.push_back(idx);
    }
    cout<<ans.size()<<"\n";
    for(const auto &x : ans){
        cout<<x + 1<<" ";
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