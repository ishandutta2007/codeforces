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
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    string s;
    cin>>s;
    int acnt = a + c + d;
    int bcnt = b + c + d;
    if(count(s.begin(), s.end(), 'A') != acnt){
        cout<<"NO\n";
        return;
    }
    vector<string> s_dec;
    int n = s.size();
    s_dec.push_back(string());
    for(int i=0;i<n;i++){
        if(s_dec.back().size() != 0 && s_dec.back().back() == s[i]){
            s_dec.emplace_back();
        }
        s_dec.back().push_back(s[i]);
    }
    vector<int> A, B, C;
    for(auto &s : s_dec){
        if(s.size() % 2) C.push_back(s.size() / 2);
        else if(s[0] == 'A') A.push_back(s.size() / 2);
        else B.push_back(s.size() / 2);
    }
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    int totext = accumulate(C.begin(), C.end(), 0);
    int c_got = accumulate(A.begin(), A.end(), 0);
    int d_got = accumulate(B.begin(), B.end(), 0);
    for(auto &x : B){
        if(c - c_got <= totext) break;
        d_got -= x;
        totext += x - 1;
    }
    for(auto &x : A){
        if(d - d_got <= totext) break;
        c_got -= x;
        totext += x - 1;
    }
    if(c_got + d_got + totext < c + d){
        cout<<"NO\n";
        return;
    }
    if(c - c_got <= totext && d - d_got <= totext){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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