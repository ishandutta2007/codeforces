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
    int n,m,p;
    cin>>n>>m>>p;
    vector<ll> msk(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j] == '1') msk[i] |= (1ll<<j);
        }
    }
    int bitc = 0;
    int idx = 0;
    ll c_val = 0;
    for(int i=0;i<30;i++){
        int x = ((rand() << 16) + rand()) % n;
        int cbit = __builtin_popcountll(msk[x]);
        vector<int> cnt(1<<cbit);
        for(int i=0;i<n;i++){
            ll val = 0;
            for(int b=0,k=0;b<60;b++){
                if(~msk[x] & (1ll<<b)) continue;
                if(msk[i] & (1ll<<b)) val |= (1ll<<k);
                ++k;
            }
            assert(val < (1<<cbit));
            cnt[val]++;
        }
        for(int i=0;i<cbit;i++){
            for(int j=(1<<cbit)-1;j>=0;--j){
                if(~j & (1<<i)) cnt[j] += cnt[j ^ (1<<i)];
            }
        }
        for(int i=0;i<(1<<cbit);i++){
            if(__builtin_popcount(i) > bitc && cnt[i] >= (n + 1) / 2){
                bitc = __builtin_popcount(i);
                idx = x;
                c_val = i;
            }
        }
    }
    ll ans = 0;
    for(int b=0,k=0;b<60;b++){
        if(~msk[idx] & (1ll<<b)) continue;
        if(c_val & (1ll<<k)) ans |= (1ll<<b);
        ++k;
    }
    for(int i=0;i<m;i++){
        if(ans & (1ll<<i)) cout<<"1";
        else cout<<"0";
    }
    cout<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}