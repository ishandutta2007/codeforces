/**
 *    author:  gary
 *    created: 07.10.2022 22:15:21
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
LL f(LL x){
    LL l=0,r=llround(ceil(sqrt(x)))+10;
    while (r*r<x){
        r++;
    }
    r++;
    while (l<r-1){
        LL mid=(l+r)>>1;
        if(mid*mid<=x) l=mid;
        else r=mid;
    }
    LL ans=l;
    l=0,r=llround(ceil(sqrt(x)))+10;
    while (r*r<x){
        r++;
    }
    r++;
    while (l<r-1){
        LL mid=(l+r)>>1;
        if(mid*(mid+1)<=x) l=mid;
        else r=mid;
    }
    ans+=l;
    l=0,r=llround(ceil(sqrt(x)))+10;
    while (r*r<x){
        r++;
    }
    r++;
    while (l<r-1){
        LL mid=(l+r)>>1;
        if(mid*(mid+2)<=x) l=mid;
        else r=mid;
    }
    ans+=l;
    return ans;
}
void solve(){
    LL l,r;
    cin>>l>>r;
    cout<<f(r)-f(l-1)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}