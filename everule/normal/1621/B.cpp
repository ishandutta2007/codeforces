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
const ll INF = 2e9 + 7;
void solve(){
    int n;
    cin>>n;
    ll lt = INF, rt = -1;
    ll cl = 0, cr = 0;
    ll cone = INF;
    for(int i=0;i<n;i++){
        ll l,r,c;
        cin>>l>>r>>c;
        if(l < lt){
            cl = c;
            lt = l;
            cone = INF;
        }
        if(l == lt){
            cl = min(c, cl);
        }
        if(r > rt){
            cr = c;
            rt = r;
            cone = INF;
        }
        if(r == rt){
            cr = min(cr, c);
        }
        if(l <= lt && r >= rt){
            cone = min(c, cone);
        }
        cout<<min(cone, cl + cr)<<"\n";
    }
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