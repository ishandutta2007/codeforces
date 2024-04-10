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
    vector<int> seq(n);
    cin>>seq;
    auto check = [&](int l,int r){
        int ans = 0;
        for(int i=l;i<=r;i++){
            ans += ((seq[i] > seq[i+1]) && (seq[i] > seq[i-1]));
            ans += ((seq[i] < seq[i+1]) && (seq[i] < seq[i-1]));
        }
        return ans;
    };
    int tot = check(1,n-2);
    int ans = tot;
    for(int i=0;i<n;i++){
        vector<int> nw(seq.begin() + max(0,i-1), seq.begin() + min(n,i+2));
        int ini = seq[i];
        int inb = check(max(1,i-1), min(n-2,i+1));
        for(auto &x : nw){
            seq[i] = x;
            ans = min(ans, tot - inb + check(max(1,i-1), min(n-2,i+1)));
        }
        seq[i] = ini;
    }
    cout<<ans<<'\n';
}
// i-2 i-1 i i+1 i+2
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}