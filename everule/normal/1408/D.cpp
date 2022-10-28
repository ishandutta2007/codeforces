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
const int MAXX = 1e6 + 7;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> rob(n);
    for(auto &[x,y] : rob){
        cin>>x>>y;
    }
    vector<pair<int,int>> light(m);
    for(auto &[x,y] : light){
        cin>>x>>y;
    }
    vector<int> yneeded(MAXX);
    for(const auto &[rx, ry] : rob){
        for(const auto &[lx, ly] : light){
            if(rx > lx){
                continue;
            }
            yneeded[lx-rx] = max(yneeded[lx-rx], ly-ry+1);
        }
    }
    //cout+yneeded;
    int ans = MAXX-1;
    for(int i=MAXX-2;i>=0;--i){
        yneeded[i] = max(yneeded[i], yneeded[i+1]);
        ans = min(ans, i + yneeded[i]);
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}