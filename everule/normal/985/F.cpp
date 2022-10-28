#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const T &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const T &vec){
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
ll modpower(ll base, ll power, ll mod){
    ll ans =1;
    base%=mod;
    while(power){
        if(power&1){
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        power>>=1;
    }
    return ans;
}
const int p1 = 1000'000'007;
const int p2 = 998'244'353;
const int AL = 26;
template<int mod, int base>
struct hasher{
    int n;
    string s;
    const int offset = 1e5;
    vector<int> invbase;
    vector<int> basepower;
    vector<array<int,26>> count;
    vector<array<int,26>> hash;
    hasher(const string &s) : s(s), n(s.size()){
        invbase.resize(n+1);
        invbase[0] = 1;
        invbase[1] = modpower(base, mod-2, mod);
        for(int i=2;i<=n;i++){
            invbase[i] = (ll)invbase[i-1]*invbase[1]%mod;
        }
        basepower.resize(n+1);
        basepower[0] = modpower(base, offset, mod);
        for(int i=1;i<=n;i++){
            basepower[i] = (ll)basepower[i-1]*base%mod;
        }
        count.resize(n+1);
        hash.resize(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<AL;j++){
                count[i+1][j]=count[i][j] + (s[i]-'a'==j);
                if(s[i]-'a' == j){
                    hash[i+1][j] = hash[i][j] + basepower[i];
                    hash[i+1][j]>mod ? hash[i+1][j]-=mod : 0;
                }
                else{
                    hash[i+1][j] = hash[i][j];
                }
            }
        }
    }
    int query(int l, int r){
        int ans = 0;
        --l;
        for(int i=0;i<AL;i++){
            int h = (ll)(hash[r][i] - hash[l][i]<0 ?  hash[r][i] - hash[l][i] + mod : hash[r][i] - hash[l][i])*invbase[l]%mod;
            //cout<<h<<" ";
            ans^=h;
        }
        //cout<<"\n";
        return ans;
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    hasher<p1,5> hash1(s);
    hasher<p2,3> hash2(s);
    for(int i=0;i<m;i++){
        int l,r,len;
        cin>>l>>r>>len;
        int l1 = hash1.query(l, l+len-1);
        int r1 = hash1.query(r, r+len-1);
        int l2 = hash2.query(l, l+len-1);
        int r2 = hash2.query(r, r+len-1);
        if(l1==r1 && l2==r2){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    solve();
}