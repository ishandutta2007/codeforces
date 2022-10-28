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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int ans = 0;
    for(int i=2;i<n;i++){
        if(s[i-2] == 'a' && s[i-1] == 'b' && s[i] == 'c') ans++;
    }
    for(int i=0;i<q;i++){
        int pos;
        char c;
        cin>>pos>>c;
        --pos;
        if(pos + 2 < n && s[pos] == 'a' && s[pos+1] == 'b' && s[pos+2] == 'c'){
            --ans;
        }
        if(pos + 1 < n && pos - 1 >= 0 && s[pos-1] == 'a' && s[pos] == 'b' && s[pos+1] == 'c'){
            --ans;
        }
        if(pos - 2 >= 0 && s[pos-2] == 'a' && s[pos-1] == 'b' && s[pos] == 'c'){
            --ans;
        }
        s[pos] = c;
        if(pos + 2 < n && s[pos] == 'a' && s[pos+1] == 'b' && s[pos+2] == 'c'){
            ++ans;
        }
        if(pos + 1 < n && pos - 1 >= 0 && s[pos-1] == 'a' && s[pos] == 'b' && s[pos+1] == 'c'){
            ++ans;
        }
        if(pos - 2 >= 0 && s[pos-2] == 'a' && s[pos-1] == 'b' && s[pos] == 'c'){
            ++ans;
        }
        cout<<ans<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}