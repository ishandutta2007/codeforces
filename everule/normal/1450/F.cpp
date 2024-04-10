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
    if(n == 1){
        cout<<"0\n";
        return;
    }
    map<pair<int,int>, int> cnt;
    int ans = 0;
    int lst = seq[0];
    for(int i=1;i<n;i++){
        if(seq[i] == seq[i-1]){
            cnt[pair(lst, seq[i-1])]++;
            ++ans;
            lst = seq[i];
        }
    }
    cnt[pair(lst, seq[n-1])]++;
    int mj = -1, mcnt = 0;
    for(const auto &[k,v] : cnt){
        if(k.first != k.second) continue;
        if(v > mcnt){
            mcnt = v;
            mj = k.second;
        }
    }
    int sf = 0;
    for(const auto &[k,v] : cnt){
        if(k.first != mj && k.second != mj){
            sf += v;
        }
    }
    int sf2 = 0;
    for(int i=1;i<n;i++){
        if(seq[i] == seq[i-1]) continue;
        if(seq[i] == mj || seq[i-1] == mj) continue;
        ++sf2;
    }
    while(mcnt > sf + 1){
        ++ans;
        mcnt-=1;
        --sf2;
    }
    if(sf2 < 0){
        cout<<"-1\n";
    }
    else{
        cout<<ans<<"\n";
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