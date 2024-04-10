#include <iostream>
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
    int ans = 1e6 + 7;
    int x,y;
    for(int i=1;i<=n;i++){
        if(n%i) continue;
        int j = n/i;
        if(ans > std::abs(j-i)){
            x = i;
            y = j;
            ans = max(j,i) - min(j,i);
        }
    }
    cout<<x<<" "<<y<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}