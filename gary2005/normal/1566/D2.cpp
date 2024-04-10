/**
 *    author:  gary
 *    created: 12.09.2021 22:32:57
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
const int MAXN=303;
int a[MAXN][MAXN],n,m;
void solve(){
    scanf("%d%d",&n,&m);
    int ans=0;
    vector<mp> f;
    rb(i,1,n*m){
        int ai;
        scanf("%d",&ai);
        f.PB(II(ai,i));
    }
    sort(ALL(f));
    int nowr=1,nowc=1;
    rep(i,n*m){
        int l=i,r=i;
        while(r+1<n*m&&f[r+1].FIR==f[r].FIR) ++r;
        rb(j,l,r){
            int cnt=min(r-j+1,m-nowc+1);
            rl(k,j+cnt-1,j){
                a[nowr][nowc++]=f[k].SEC;
            }
            j+=cnt-1;
            if(nowc==m+1){
                nowc=1;
                nowr++;
            }
        }
        i=r;
    }
    // rb(i,1,n){
    //     rb(j,1,m){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    rb(i,1,n){
        rb(j,1,m){
            rb(x,1,j-1){
                ans+=a[i][x]<a[i][j];
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}