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
const int AL = 26;
void solve(){
    ll n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    t -= (1ll<<(s.end()[-1] - 'a'));
    t += (1ll<<(s.end()[-2] - 'a'));
    n-=2;
    s.pop_back();s.pop_back();
    vector<int> cnt(AL);
    for(auto &c : s){
        cnt[c-'a']++;
        t += (1ll<<(c-'a'));
    }
    for(int i=AL-1;i>=0;--i){
        while(cnt[i] && t >= (1ll<<(i+1))){
            t -= (1ll<<(i+1));
            --cnt[i];
        }
    }
    if(t == 0){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}