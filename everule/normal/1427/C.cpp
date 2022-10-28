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
struct Celeb{
    int x,y,t;
    Celeb(){}
    Celeb(int x,int y,int t) : x(x), y(y), t(t) {}
};
void solve(){
    int r,n;
    cin>>r>>n;
    vector<Celeb> celebs(n);
    for(auto &[x,y,t] : celebs){
        cin>>t>>x>>y;
    }
    celebs.insert(celebs.begin(), {1,1,0});
    vector<int> pref(n+1);
    pref[0] = 0;
    vector<int> dp(n+1, -1e9);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;--j){
            if(celebs[i].t - celebs[j].t >= 2*r){
                dp[i] = max(dp[i], pref[j]+1);
                break;
            }
            if(abs(celebs[i].x - celebs[j].x) + abs(celebs[i].y - celebs[j].y) <= celebs[i].t - celebs[j].t){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        pref[i] = max(pref[i-1], dp[i]);
    }
    //cout+dp;
    cout<<*max_element(dp.begin(), dp.end())<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}