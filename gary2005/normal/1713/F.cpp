/**
 *    author:  gary
 *    created: 06.08.2022 22:33:01
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
const int MAXN=5e5+10;
int n,b[MAXN],a[MAXN],tmp[MAXN];
void FWT(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    rb(i,l,r) tmp[i]=0;
    rb(i,l,mid) tmp[i]=a[mid+1+i-l];
    rb(i,mid+1,r) tmp[i]=a[i-mid-1+l]^a[i];
    rb(i,l,r) a[i]=tmp[i];
    FWT(l,mid);
    FWT(mid+1,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rep(i,n) cin>>b[i];
    int N=n;
    vector<int> x;
    while (N){
        int now=1;
        while (now*2<=N){
            now<<=1;
        }
        N-=now;
        x.push_back(now);
    }
    int from=0;
    from=0;
    int len;
    len=n;
    for(auto it:x){
        len-=it;
        rep(j,len) b[from+it+j]^=b[from+j];
        rep(j,it) a[from+j]=b[from+j];
        FWT(from,from+it-1);
        from+=it;
    }
    // rl(i,n-1,0) cout<<a[i]<<' ';
    // cout<<endl;
    from=n-x.back();
    len=0;
    rl(i,x.size()-1,0){
        rep(j,len) a[from+j]^=a[from+x[i]+j];
        if(i==0) break;
        from-=x[i-1];
        len+=x[i];
    }
    rl(i,n-1,0) cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}