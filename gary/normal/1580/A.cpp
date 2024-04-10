/**
 *    author:  gary
 *    created: 30.09.2021 18:03:36
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
int a[404][404],cnt0[404],cnt1[404],pre[404][404],cnt2[404];
void solve(){
    int n,m;
    cin>>n>>m;
    rb(i,1,n) rb(j,1,m){
        char c;
        cin>>c;
        a[i][j]=c-'0';
    }
    rb(i,1,n) rb(j,1,m) pre[i][j]=(pre[i-1][j]+a[i][j]);
    int ans=INF;
    rb(i,1,n){
        rb(j,i+5-1,n){
            rb(k,1,m){
                cnt0[k]=cnt0[k-1]+(a[i][k]==0);
                cnt1[k]=cnt1[k-1]+(a[j][k]==0);
                cnt2[k]=cnt2[k-1]+(pre[j-1][k]-pre[i][k]);
            }
            int bst=INF;
            rb(k,1,m){
                if(k>=4){
                    check_min(bst,(j-i-1-pre[j-1][k-3]+pre[i][k-3])-cnt0[k-3]-cnt1[k-3]-cnt2[k-3]);
                    check_min(ans,cnt0[k-1]+cnt1[k-1]+cnt2[k-1]+bst+(j-i-1-pre[j-1][k]+pre[i][k]));
                }
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}