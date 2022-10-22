/**
 *    author:  gary
 *    created: 30.09.2022 22:31:50
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> v(k);
        rep(i,k) cin>>v[i];
        if(k==1){
            cout<<"Yes\n";
            continue;
        }
        LL ele=v[1]-v[0];
        bool ok=1;
        rep(i,k-1) if(i){
            ok&=v[i+1]-v[i]>=v[i]-v[i-1];
        }
        if(!ok||1ll*(n-k+1)*ele<v[0]){
            cout<<"No\n";
            continue;
        }
        else{
            cout<<"Yes\n";
        }
    }
    return 0;
}