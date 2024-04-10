/**
 *    author:  gary
 *    created: 02.08.2022 08:58:31
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
int x[1<<18];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,r;
    cin>>n>>r;
    double sum=0;
    rep(mask,1<<n){
        cin>>x[mask];
        sum+=x[mask];
    }
    cout<<fixed<<setprecision(10)<<sum/(1<<n)<<'\n';
    rb(i,1,r){
        int z,g;
        cin>>z>>g;
        sum-=x[z];
        x[z]=g;
        sum+=x[z];
        cout<<fixed<<setprecision(10)<<sum/(1<<n)<<'\n';
    }
    return 0;
}