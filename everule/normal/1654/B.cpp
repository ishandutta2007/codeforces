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
const int AL = 26;
const int INF = 1e9;
void solve(){
    vector<int> last(AL, INF);
    string s;
    cin>>s;
    int n = s.size();
    for(int i=0;i<n;i++){
        last[s[i]-'a'] = i;
    }
    int ans = *min_element(last.begin(), last.end());
    cout<<s.substr(ans, n-ans)<<"\n";
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