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
    vector<array<int, 2>> a(n), b(n);
    vector<array<int, 2>> s(n);
    for(int i=0;i<n;i++){
        cin>>a[i][0];
        s[i][0] = a[i][0];
        a[i][1] = i;
    }
    for(int i=0;i<n;i++){
        cin>>b[i][0];
        s[i][1] = b[i][0];
        b[i][1] = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> sb(n+1, 1e9 + 7), pb(n+1);
    for(int i=1;i<=n;i++){
        pb[i] = max(pb[i-1], s[a[i-1][1]][1]);
    }
    for(int i=n-1;i>=0;--i){
        sb[i] = min(sb[i+1], s[a[i][1]][1]);
    }
    int ans = 0;
    for(int i=n-1;i>0;--i){
        if(pb[i] < sb[i]){
            ans = i;
            break;
        }
    }
    string fin(n, '0');
    for(int i=ans;i<n;i++){
        fin[a[i][1]] = '1';
    }
    cout<<fin<<"\n";
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