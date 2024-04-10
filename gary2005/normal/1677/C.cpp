/**
 *    author:  gary
 *    created: 08.05.2022 22:57:26
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e5+10;
int n,ca[MAXN],cb[MAXN],fa[MAXN],sz[MAXN];
LL f(int x){
    return 1ll*x*(x-1)/2+(x/2);
}
LL g(int x){
    return x-1+(x%2==0);
}
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
int cnt=0;
void solve(){
    ++cnt;
    cin>>n;
    rb(i,1,n) cin>>ca[i];
    rb(i,1,n) cin>>cb[i];
    rb(i,1,n) fa[i]=i,sz[i]=0;
    rb(i,1,n) fa[root(ca[i])]=root(cb[i]);
    rb(i,1,n) sz[root(i)]++;
    LL sum=0;
    LL ans=0;
    vector<int> X;
    rb(i,1,n) if(root(i)==i){
        X.PB(sz[i]);
        ans+=f(sz[i]);
        // cout<<sz[i]<<endl;
    }
    int c=0;
    for(auto it:X){
        c+=it/2;
    }
    cout<<2ll*c*(n-c)<<endl;
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