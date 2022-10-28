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
    vector<int> a(n), b(n);
    cin>>a>>b;
    vector<int> c1(2*MAXA + 1), c2(2*MAXA + 1);
    for(auto &x : a) c1[x+MAXA]++;
    for(auto &x : b) c2[x+MAXA]++;
    bool ans = 1;
    for(int i=2*MAXA;i>0;--i){
        if(c2[i] < c1[i] || c1[i] < 0){
            ans = 0;
            break;
        }
        c1[i-1] -= c2[i] - c1[i];
    }
    cout<<(ans ? "Yes" : "No")<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}