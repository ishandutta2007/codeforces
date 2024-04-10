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
bool isPrime(int x){
    if(x == 2 || x == 3) return true;
    if(x % 2 == 0 || x % 3 == 0){
        return false;
    }
    for(int i=5;i*i<=x;i+=4){
        if(x > i && x % i == 0) return false;
        i += 2;
        if(x > i && x % i == 0) return false;
    }
    return true;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    cin>>a;
    vector<int> divs;
    for(int i=1;i<n;i++){
        if(n % i == 0 && isPrime(n / i))divs.push_back(i);
        
    }
    vector<vector<ll>> div_mod_answers(divs.size());
    for(int i=0;i<divs.size();i++){
        div_mod_answers[i].assign(divs[i], 0);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<divs.size();j++){
            div_mod_answers[j][i % divs[j]] += 1ll * divs[j] * a[i];
        }
    }
    vector<multiset<ll>> answers(divs.size());
    ll ans = 0;
    for(int i=0;i<div_mod_answers.size();i++){
        for(int j=0;j<div_mod_answers[i].size();j++){
            answers[i].insert(div_mod_answers[i][j]);
        }
        ans = max(ans, *answers[i].rbegin());
    }
    cout<<ans<<"\n";
    while(q--){
        int p,x;
        cin>>p>>x;
        --p;
        ll ans = 0;
        for(int i=0;i<div_mod_answers.size();i++){
            answers[i].erase(answers[i].find(div_mod_answers[i][p % divs[i]]));
            div_mod_answers[i][p % divs[i]] += 1ll * divs[i] * (x - a[p]);
            answers[i].insert(div_mod_answers[i][p % divs[i]]);
            ans = max(ans, *answers[i].rbegin());
        }
        a[p] = x;
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