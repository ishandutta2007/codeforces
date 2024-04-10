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
    int n,k;
    cin>>n>>k;
    vector<int> ans(n);
    for(int i=0;i<n;i++) ans[i] = n - i - 1;
    if(k != n-1){
        ans[k] = n-1;
        ans[n-1] = k;
        ans[0] = n - k - 1;
        ans[n-k-1] = 0;
        ll tot = 0;
        for(int i=0;i<n;i++){
            if(i < ans[i]){
                cout<<i<<" "<<ans[i]<<"\n";
                tot += (i & ans[i]);
            }
        }
        assert(tot == k);
        return;
    }
    if(n == 4){
        cout<<"-1\n";
        return;
    }
    ans[0] = 1;
    ans[1] = 0;
    ans[n-1] = n - 2;
    ans[n-2] = n - 1;
    ans[2] = n - 4;
    ans[n-4] = 2;
    ans[3] = n - 3;
    ans[n-3] = 3;
    ll tot = 0;
    for(int i=0;i<n;i++){
        if(i < ans[i]){
            cout<<i<<" "<<ans[i]<<"\n";
            tot += (i & ans[i]);
        }
    }
    assert(tot == k);
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