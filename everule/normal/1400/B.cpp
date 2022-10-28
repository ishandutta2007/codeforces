#include <iostream>
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
    int p,f;
    cin>>p>>f;
    int cs,cw;
    cin>>cs>>cw;
    int s,w;
    cin>>s>>w;
    if(s>w){
        swap(s,w);
        swap(cs,cw);
    }
    if(p<f){
        swap(p,f);
    }
    int ans = 0;
    for(int i=0;i<=cs;i++){
        if(i*s > p) break;
        int curr = i;
        int mxs = min(cs - i, f/s);
        curr+=mxs;
        curr+=min((p-i*s)/w +  (f-mxs*s)/w, cw);  
        ans = max(ans, curr);
    }
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