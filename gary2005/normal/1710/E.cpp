/**
 *    author:  gary
 *    created: 27.07.2022 21:04:47
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
const int MAXN=2e5+20;
int a[MAXN],b[MAXN],r[MAXN],c[MAXN];
LL sumr[MAXN],sumc[MAXN];
int x,y;
int n,m;
int X;
LL calc(int V,int H,bool era){
    LL rest=0;
    rest=1ll*n*V+1ll*H*m-2ll*H*V;
    if(H!=n&&V!=m&&a[H+1]+b[V+1]>X){
        int T=r[H+1];
        rest+=sumc[T]-sumc[V]-1ll*H*(T-V);
    }
    if(H>0&&V>0&&a[H]+b[V]<=X){
        int T=r[H];
        rest+=sumc[T]-sumc[V]-1ll*H*(T-V);
    }
    if(era){
        rest-=x>H||y>V;
    }
    return rest;
}
bool check(int mid){
    X=mid;
    r[0]=m;
    rb(i,1,n) {r[i]=r[i-1];while(r[i]&&b[r[i]]+a[i]<=mid) r[i]--;sumr[i]=sumr[i-1]+r[i];}
    c[0]=n;
    rb(i,1,m) {c[i]=c[i-1];while(c[i]&&a[c[i]]+b[i]<=mid) c[i]--;sumc[i]=sumc[i-1]+c[i];}
    int H=0;
    LL best1=1e18,best2=1e18;
    rb(V,0,m){
        while (H<n&&calc(V,H+1,0)<=calc(V,H,0)){
            ++H;
        }
        check_min(best1,calc(V,H,0));
    }
    H=0;
    rb(V,0,m){
        while (H<n&&calc(V,H+1,1)<=calc(V,H,1)){
            ++H;
        }
        check_min(best2,calc(V,H,1));
    }
    // cout<<best1<<' '<<best2<<endl;
    return best1!=best2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rb(i,1,n) cin>>a[i];
    rb(i,1,m) cin>>b[i];
    vector<mp> v;
    rb(i,1,n) v.emplace_back(a[i],i);
    sort(ALL(v));
    reverse(ALL(v));
    rep(i,n) if(v[i].second==1) x=i+1;
    v.clear();
    rb(i,1,m) v.emplace_back(b[i],i);
    sort(ALL(v));
    reverse(ALL(v));
    rep(i,m) if(v[i].second==1) y=i+1;
    int l=2,r=a[1]+b[1];
    sort(a+1,a+1+n);reverse(a+1,a+1+n);
    sort(b+1,b+1+m);reverse(b+1,b+1+m);
    // check(2);
    // return 0;
    while (l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}