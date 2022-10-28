#include <bits/stdc++.h>
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
    for(auto &x : a) --x;
    for(auto &x : b) --x;
    vector<int> decomp(n);
    for(int i=n-1;i>=0;--i){
        int curr = 0;
        while(b.size() > 0 && b.back() == a[i]){
            ++curr;
            b.pop_back();
        }
        decomp[i] = curr;
    }
    if(b.size() > 0){
        cout<<"NO\n";
        return;
    }
    vector<int> cnt(n);
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
        cnt[a[i]] -= decomp[i];
        if(cnt[a[i]] < 0){
            cout<<"NO\n";
            return;
        }   
    }
    cout<<"YES\n";
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