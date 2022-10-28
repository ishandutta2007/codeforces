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
const int m = 6;
void solve(){
    vector<int> a(m);
    cin>>a;
    sort(a.begin(), a.end(), greater<int>());
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    vector<pair<int,int>> updates;
    updates.reserve(n*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            updates.push_back({i,j});
        }
    }
    sort(updates.begin(), updates.end(), [&](const pair<int,int> &x, const pair<int,int> &y){
        return seq[x.first] - a[x.second] < seq[y.first] - a[y.second];
    });
    int mx = *max_element(seq.begin(), seq.end()) - a[0];
    int ans = mx - (*min_element(seq.begin(), seq.end()) - a[0]);
    multiset<int> minimums;
    for(int i=0;i<n;i++){
        minimums.insert(seq[i] - a[0]);
    }
    int u = updates.size();
    vector<int> mn(u+1);
    mn[u] = *min_element(seq.begin(), seq.end()) - a[m-1];
    for(int i=u-1;i>=0;--i){
        mn[i] = min(seq[updates[i].first] - a[updates[i].second], mn[i+1]);
    }
    for(int i=0;i<u;i++){  
        mx = max(mx, seq[updates[i].first] - a[updates[i].second+1]);
        ans = min(ans, mx - mn[i+1]); 
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}