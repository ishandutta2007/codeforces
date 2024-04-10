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
    int offset = 0;
    vector<pair<int,int>> ans;
    int p2 = 1;
    while(p2*2<=n){
        p2*=2;
    }
    for(int len=1;len<=p2;len<<=1){
        vector<bool> used(p2);
        for(int i=0;i+len<p2;i++){
            if(!used[i]){
                ans.pb({i,i+len});
                used[i+len] = 1;
            }
        }
    }
    if(p2!=n){
        for(int len=1;len<=p2;len<<=1){
            vector<bool> used(p2);
            for(int i=0;i+len<p2;i++){
                if(!used[i]){
                    ans.pb({i+n-p2,i+len+n-p2});
                    used[i+len] = 1;
                }
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(const auto &[x,y] : ans){
        cout<<x+1<<" "<<y+1<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}