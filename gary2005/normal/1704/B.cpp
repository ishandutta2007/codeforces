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
int n;
LL x,a[200000+20];
void solve(){
    cin>>n>>x;
    vector<LL> num;
    rb(i,1,n) cin>>a[i];
    int answer=0;
    LL l=-2e9,r=2e9;
    rb(i,1,n){
        check_min(r,a[i]+x);
        check_max(l,a[i]-x);
        if(l>r){
            answer++;
            l=a[i]-x;
            r=a[i]+x;
        }
    }
    cout<<answer<<endl;
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