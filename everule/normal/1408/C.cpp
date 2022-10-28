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
    using ld = long double;
    int n,l;
    cin>>n>>l;
    vector<ld> seq(n);
    cin>>seq;
    seq.insert(seq.begin(), 0);
    seq.insert(seq.end(), l);
    n+=2;
    vector<ld> t1(n), t2(n);
    t1[0] = 0;
    for(int i=1;i<n;i++){
        t1[i] = t1[i-1] + (seq[i]-seq[i-1])/i;
    }
    t2[n-1] = 0;
    for(int i=n-2;i>=0;--i){
        t2[i] = t2[i+1] + (seq[i+1] - seq[i])/(n-i-1);
    }
    //cout+t1+t2;
    for(int i=1;i<n;i++){
        if(t1[i] > t2[i]){
            --i;
            ld dist = seq[i+1] - seq[i];
            dist+=(i+1)*(t1[i] - t2[i+1]);
            dist/=n;
            cout<<fixed<<setprecision(11)<<dist+t2[i+1]<<"\n";
            return;
        }
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