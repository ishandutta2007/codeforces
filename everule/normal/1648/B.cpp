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
    int n,c;
    cin>>n>>c;
    vector<int> a(n);
    vector<int> cnt(c + 1);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cnt[a[i]]++;
    vector<int> pcnt(c + 2);
    for(int i=1;i<=c+1;i++){
        pcnt[i] = pcnt[i-1] + cnt[i-1];
    }
    auto getRange = [&](int l,int r){
        return pcnt[min(c+1, r+1)] - pcnt[l];
    };
    bool ans = 1;
    for(int i=1;i<=c;i++){
        if(cnt[i] == 0) continue;
        for(int j=1;i*j<=c;j++){
            if(getRange(i * j, i * (j + 1) - 1)){
                if(cnt[j] == 0) ans = 0;
            }
        }
    }
    cout<<(ans ? "Yes" : "No")<<"\n";
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