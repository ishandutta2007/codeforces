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
    function<int(int,int)> query = [&](int l,int r){
        cout<<"? "<<l<<" "<<r<<endl;
        int ans;
        cin>>ans;
        return ans;
    };
    int x = query(1,3), y = query(1,2), z = query(2,3);
    vector<int> ans(n);
    ans[0] = x-z;
    ans[1] = y+z-x;
    ans[2] = x-y;
    for(int i=3;i<n;i++){
        ans[i] = query(i,i+1) - ans[i-1];
    }
    cout<<"! ";
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}