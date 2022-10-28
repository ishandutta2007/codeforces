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
const int MAXT = 300;
void solve(){
    auto query = [&](string t){
        cout<<t<<"\n";
        cout.flush();
        int ans;
        cin>>ans;
        return ans;
    };
    int v1 = query(string(MAXT, 'a'));
    int v2 = query(string(MAXT, 'b'));
    int len = 2 * MAXT - v1 - v2;
    string ans(len, 'a');
    int acnt = (v2 - v1 + len) / 2;
    int bcnt = len - acnt;
    int oa = 0;
    for(int i=0;i<len-1;i++){
        string t(len, 'a');
        t[i] = 'b';
        int q = query(t);
        if(q < bcnt) ans[i] = 'b';
        else oa++;
    }
    if(oa == acnt) ans[len - 1] = 'b';
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}