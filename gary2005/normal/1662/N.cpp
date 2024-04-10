/**
 *    author:  gary
 *    created: 24.04.2022 21:26:16
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
const int MAXN=1505;
int a[MAXN][MAXN],n,r1[MAXN][MAXN],r2[MAXN][MAXN];
int cntr[MAXN],cntc[MAXN];
mp pos[MAXN*MAXN];
int main(){
    scanf("%d",&n);
    rb(i,1,n) rb(j,1,n) scanf("%d",&a[i][j]),pos[a[i][j]]=II(i,j);
    __int128_t ans=0;
    rb(j,1,n){
        vector<mp> v;
        rb(i,1,n) v.PB({a[i][j],i});
        sort(ALL(v));
        rep(i,v.size()){
            r1[v[i].second][j]=i;
        }
    }
    rb(i,1,n){
        vector<mp> v;
        rb(j,1,n) v.PB({a[i][j],j});
        sort(ALL(v));
        rep(j,v.size()){
            r2[i][v[j].second]=j;
        }
    }
    ans=1ll*n*n*(n-1)*(n-1);
    rb(i,1,n){
        rb(j,1,n)
            ans-=r1[i][j]*r2[i][j];
    }
    ans=-ans;
    rb(x,1,n*n){
        int i,j;
        tie(i,j)=pos[x];
        ans+=(x-1)-cntr[i]-cntc[j];
        cntr[i]++;
        cntc[j]++;
    }
    cout<<(LL)(-ans)<<endl;
    return 0;
}