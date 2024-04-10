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
    int n,k;
    cin>>n>>k;
    vector<ll> seq(n);
    cin>>seq;
    sort(seq.begin(), seq.end());
    vector<int> val(n+1);
    val[0] = 0;
    int cnt = 0;
    vector<ll> dp1(n+1);
    dp1[0] = 0;
    for(int i=0;i<n;i++){
        dp1[i+1] = dp1[i] + seq[i] * val[i];
        ++cnt;
        val[i+1] = val[i];
        if(cnt == k + 1){
            cnt = 0;
            val[i+1]++;
        }
    }
    vector<ll> ssum(n+1);
    for(int i=n-1;i>=0;--i){
        ssum[i] = ssum[i+1] + seq[i];
    }
    vector<ll> swsum(n+1);
    for(int i=n-1;i>=0;--i){
        swsum[i] = swsum[i+1] + i * seq[i];
    }
    ll ans = swsum[0];
    for(int i=1;i<=n;i++){
        ans = max(ans, dp1[i] + swsum[i] - (i-val[i])*ssum[i]);
    }
    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}