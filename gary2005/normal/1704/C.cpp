/**
 *    author:  gary
 *    created: 31.07.2022 21:47:45
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    rep(i,m) cin>>a[i];
    sort(ALL(a));
    vector<int> len;
    len.push_back(a[0]+n-a.back()-1);
    rep(i,a.size()-1) len.push_back(a[i+1]-a[i]-1);
    LL ans=0;
    priority_queue<int> two,one;
    for(auto it:len) two.push(it);
    rb(i,0,10*m){
        while (!two.empty()&&two.top()-2*i<=0){
            two.pop();
        }
        while (!one.empty()&&one.top()-i<=0){
            one.pop();
        }
        if(two.empty()&&one.empty()) break;
        if(two.empty()||(!one.empty()&&one.top()-i>=two.top()-2*i)){
            ans+=one.top()-i;
            one.pop();
        }
        else{
            if(two.top()-2*i==1){
                ans++;
                two.pop();
            }
            else{
                one.push(two.top()-i);
                two.pop();
            }
        }
    }
    cout<<n-ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}