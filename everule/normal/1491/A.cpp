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
    int n,q;
    cin>>n>>q;
    vector<int> seq(n);
    array<int, 2> cnt = {0,0};
    for(auto &x : seq) cin>>x;
    for(auto &x : seq) cnt[x]++;
    for(int i=0;i<q;i++){
        int t,x;
        cin>>t>>x;
        if(t == 1){
            --x;
            cnt[seq[x]]--;
            seq[x] = 1 - seq[x];
            cnt[seq[x]]++;
        }
        if(t == 2){
            cout<<(cnt[1] >= x)<<"\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}