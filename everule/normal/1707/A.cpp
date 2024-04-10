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
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    cin>>a;
    int curr_contest = 0;
    int l = 0, r = n;
    while(l < r){
        int mid = (l + r) / 2;
        int cq = q;
        bool can_do = 1;
        for(int i=mid;i<n;i++){
            if(cq <= 0) can_do = 0;
            if(a[i] > cq) --cq;
        }
        if(can_do){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    string s(n, '0');
    for(int i=0;i<n;i++){
        if(i >= l || a[i] <= q) s[i] = '1';
    }
    cout<<s<<"\n";
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