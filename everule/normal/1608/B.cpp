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
    int n,a,b;
    cin>>n>>a>>b;
    if(a + b > n - 2 || abs(a - b) > 1){
        cout<<"-1\n";
        return;
    }
    bool sw = 0;
    if(a < b) swap(a, b), sw = 1;
    vector<int> ans;
    int mss = -1;
    //1 n 2 n-1 3 n-2  
    if(a == b){
        int x = b + 2;
        for(int i=0;i<a;i++){
            ans.push_back(i + 1);
            ans.push_back(x + i);
        }
        if(a == b) ans.push_back(b + 1);
        for(int i=x+a;i<=n;i++){
            ans.push_back(i);
        }
    }
    if(a == b + 1){
        int x = b + 1;
        for(int i=0;i<x;i++){
            ans.push_back(i + 1);
            ans.push_back(n - i);
        }
        for(int i=n-x;i>x;--i){
            ans.push_back(i);
        }
    }
    if(sw == 1){
        for(auto &x : ans) x = n - x + 1;
    }
    //assert(ans.size() == n);
    cout+ans;
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