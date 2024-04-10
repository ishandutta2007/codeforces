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
    string s;
    cin>>s;
    string a(n, '0'), b(n, '0');
    int sum = 0;
    bool last = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            a[i] = '(';
            b[i] = '(';
            sum++;
        }
        if(s[i] == '0'){
            a[i] = (last ? ')' : '(');
            b[i] = (last ? '(' : ')');
            last ^= 1;
        }
    }
    if(sum%2 != 0){
        cout<<"NO\n";
        return;
    }
    for(int i=n-1;i>=0;--i){
        if(sum > 0 && s[i] == '1'){
            a[i] = ')';
            b[i] = ')';
            sum-=2;
        }  
    }
    auto check = [&](string s){
        int sum = 0;
        for(auto &c : s){
            if(c == '(') sum++;
            if(c == ')') sum--;
            if(sum < 0) return false;
        }
        if(sum != 0) assert(false);
        return true;
    };
    if(check(a) && check(b)){
        cout<<"YES\n";
        cout<<a<<"\n"<<b<<"\n";
        return;
    }
    cout<<"NO\n";
    return;
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