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
using ld = long double;
ld eps = 1e-12;
void solve(){
    int n,r,v;
    cin>>n>>r>>v;
    cout<<fixed<<setprecision(10);
    for(int i=0;i<n;i++){
        int s,f;
        cin>>s>>f;
        ld d = f - s;
        ld mn = 0;
        ld mx = d/r;
        for(int i=0;i<70;i++){
            ld mid = mn + mx;
            mid/=2;
            if((cosl(mid) - 1)*(cosl(mid) - 1) + sinl(mid)*sinl(mid) <= ((d/r) - mid) * (d/r - mid)){
                mn = mid;
            }
            else{
                mx = mid;
            }
        }
        cout<<mn*r/v<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}