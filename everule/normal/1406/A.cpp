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
const int MAXA = 100;
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    vector<int> count(MAXA + 1);
    for(auto &x : seq) count[x]++; 
    int d = find_if(count.begin(), count.end(), [&](int x){return x<2;}) - count.begin();
    int s = find_if(count.begin(), count.end(), [&](int x){return x<1;}) - count.begin();
    cout<<d + s<<"\n";
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