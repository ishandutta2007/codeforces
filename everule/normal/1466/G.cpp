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
const int MAXQ = 1e6 + 7;
const int AL = 26;
const int p = 1e9 + 7;
ll modpower(ll base, ll power, ll mod=p){
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
void solve(){
    int n,q;
    cin>>n>>q;
    vector<string> songs(1);
    string t;
    cin>>songs>>t;
    while(songs.size() <= n && songs.back().size() <= MAXQ){
        songs.push_back(songs.back() + t[songs.size() - 1] + songs.back());
    }
    auto pi_func = [&](string &w){
        vector<int> pi(w.size());
        for(int i=1;i<w.size();i++){
            int j = pi[i-1];
            while(j > 0 && w[i] != w[j]) j = pi[j-1];
            if(w[i] == w[j]) ++j;
            pi[i] = j;
        }
        return pi;
    };
    auto matches = [&](string &w, string &s){
        auto pi = pi_func(w);
        int j = 0;
        int ans = 0;
        for(auto &c : s){
            while(j > 0 && c!=w[j]) j = pi[j-1];
            if(c == w[j]) ++j;
            if(j == w.size()) ans++, j = pi[j-1];
        }
        return ans;
    };
    auto z_func = [&](string &s){
        int n = s.size();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    };
    auto left_valid = [&](string &w, string &s){
        vector<bool> v(w.size(), 1);
        string x = w + '!' + s;
        auto z = z_func(x);
        for(int i=1;i<w.size();i++){
            v[i] = (z[x.size() - i] == i);
        }
        return v;
    };
    auto right_valid = [&](string &w, string &s){
        vector<bool> v(w.size(), 1);
        string x = s + '!' + w;
        auto z = z_func(x);
        for(int i=1;i<w.size();i++){
            v[i] = (z[x.size() - i] == i);
        }
        return v;
    };
    vector<array<int, AL>> psum(n + 1);
    for(ll i=1,p2=modpower(2,n-1);i<=n;i++){
        for(int j=0;j<AL;j++){
            psum[i][j] = psum[i-1][j];
            if(t[i-1]-'a' == j){
                psum[i][j] += p2;
                if(psum[i][j] >= p) psum[i][j]-=p;
            }
        }
        p2 *= (p+1)/2;
        p2 %= p;
    }
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        string w;
        cin>>w;
        if(k < songs.size() && songs[k].size() < 3*w.size()){
            cout<<matches(w, songs[k])<<"\n";
            continue;
        }
        int l = 0;
        while(songs[l].size() <= w.size()) ++l;
        auto vl = left_valid(w, songs[l]);
        auto vr = right_valid(w, songs[l]);
        array<int, AL> cnt;
        fill(cnt.begin(), cnt.end(), 0);
        for(int i=0;i<w.size();i++){
            if(vl[i] && vr[w.size() - i - 1]){
                ++cnt[w[i]-'a'];
            }
        }
        int inv = modpower((p+1)/2, n-k);
        ll fin = matches(w, songs[l]) * modpower(2, k-l);
        for(int i=0;i<AL;i++){
            ll ans = psum[k][i] - psum[l][i];
            if(ans < 0) ans+=p;
            ans *= inv;
            ans %= p;
            ans *= cnt[i];
            ans %= p;
            fin += ans;
        }
        cout<<fin%p<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}