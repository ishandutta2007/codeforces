#include <bits/stdc++.h>
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
template<int... mods>
struct StringHash{
    StringHash(const string &s){}
    int hashval(int l1,int r2){
        return 0;
    }
    int compare(int l1,int r1,int l2,int r2){
        return true;
    }
};
template<int mod,int... mods>
struct StringHash<mod, mods...>{
    StringHash(){}
    int modpow(ll x,ll p){
        ll ans = 1;
        while(p){
            if(p&1) ans*=x, ans%=mod;
            x*=x;
            x%=mod;
            p>>=1; 
        }
        return int(ans);
    }
    vector<int> hashvalues;
    vector<int> pows;
    vector<int> invpows;
    StringHash<mods...> ohash;
    const int AL = 26;
    StringHash(const string &s) : ohash(s){
        int n = s.size();
        hashvalues.resize(n+1);
        pows.resize(n+1);
        invpows.resize(n+1);
        pows[0] = 1;
        for(int i=1;i<=n;i++){
            pows[i] = ll(AL + 1) * pows[i-1] % mod;
        }
        invpows[n] = modpow(pows[n], mod-2);
        for(int i=n-1;i>=0;--i){
            invpows[i] = ll(AL + 1) * invpows[i+1] % mod;
        }
        for(int i=1;i<=n;i++){
            hashvalues[i] = (ll(AL + 1) * hashvalues[i-1] + (s[i-1] - 'a' + 1)) % mod;
        }
    }
    int hashval(int l1,int r1){ // 0 indexed
        ll ans = hashvalues[r1+1] - ll(hashvalues[l1]) * pows[r1-l1+1];
        ans%=mod;
        return ans >= 0 ? ans : ans+mod;
    }
    bool compare(int l1,int r1, int l2,int r2){
        return hashval(l1,r1) == hashval(l2, r2) && ohash.compare(l1,r1,l2,r2);
    }
};
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t = s;
    reverse(t.begin(), t.end());
    s += t;
    for(int i=0;i<2*n;i++){
        s[i] = (s[i] == '(') ? 'a' : 'b';
    }
    //cout<<s<<"\n";
    StringHash<int(1e9) + 7, 998244353> hash(s);
    int op = 0;
    int l = 0;
    int cp = 0;
    bool bad = 0;
    for(int r=0;r<n;r++){
        if(s[r] == 'a'){
            cp += 1;
        }
        else{
            cp -= 1;
        }
        if(cp < 0){
            bad = 1;
        }
        if(!bad && cp == 0){
            l = r+1;
            op++;
        }
        if(r - l >= 1 && hash.compare(l, r, 2*n-r-1, 2*n-l-1)){
            l = r+1;
            op++;
            bad = 0;
            cp = 0;
        }
    }
    cout<<op<<" "<<n-l<<"\n";
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