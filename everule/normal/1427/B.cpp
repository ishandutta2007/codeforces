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
    string s;
    cin>>s;
    vector<int> gaps;
    for(int i=0, st = -1e9;i<n;i++){
        if(s[i]=='L'){
            ++st;
        }
        else{
            if(st > 0) gaps.pb(st);
            st = 0;
        }
    }
    int ans = (s[0]=='W');
    for(int i=1;i<n;i++){
        if(s[i]=='W'){
            ++ans;
            if(s[i-1]=='W'){
                ++ans;
            }
        }
    }
    sort(gaps.begin(), gaps.end());
    for(const auto &g : gaps){
        if(g<=k){
            k-=g;
            ans+=2*g + 1;
        }
        else if(k<g){
            ans+=2*k;
            k = 0;
        }
    }
    int ext = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='W'){
            break;
        }
        ++ext;
    }
    for(int i=n-1;i>=0;--i){
        if(s[i]=='W'){
            break;
        }
        ++ext;
    }
    if(ext > n){
        cout<<max(0,2*k-1)<<"\n";
        return;
    }
    ans+=min(k,ext)*2;
    cout<<ans<<"\n";
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