/**
 *    author:  gary
 *    created: 19.06.2022 17:02:11
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
const int MAXN=2e5+20;
int n,a[2][MAXN],b[2][MAXN];
map<int,int> dp;
void upd(int x,int y){
    if(dp.find(x)!=dp.end()){
        if(dp[x]>y) dp[x]=y;
    }
    else{
        dp[x]=y;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sum=0;
    cin>>n;
    rep(i,2){
        rb(j,1,n){
            cin>>a[i][j];
            b[i][j]=a[i][j];
            if(a[i][j]){
                sum++;
            }
        }
    }
    LL ans=0;
    ans=0;
    rep(i,2){
        rb(j,1,n){
            cin>>a[i][j];
            if(a[i][j]){
                sum--;
            }
            a[i][j]-=b[i][j];
        }
    }
    if(sum!=0){
        cout<<-1<<endl;
        return 0;
    }
    int sum2=0;
    rb(j,1,n){
        sum2+=a[0][j]+a[1][j];
        ans+=abs(sum2);
    }
    rep(i,2)
    rb(j,1,n) b[i][j]=b[i][j-1]+a[i][j];
    // rep(i,2){
        // rb(j,1,n){
            // cout<<b[i][j]<<" ";
        // }
        // cout<<endl;
    // }
    dp[0]=0;
    rb(j,1,n){
        // b[0][j]+x <0 b[1][j]-x >0
        // x< -b[0][j] x<b[1][j]
        auto ite=dp.lower_bound(min(-b[0][j],b[1][j]));
        int newdp[2]={INF,INF};
        int v[2]={-b[0][j],b[1][j]};
        if(ite!=dp.begin()){
            --ite;
            vector<int> X;
            while (true){
                X.PB(ite->first);
                if(ite==dp.begin()) break;
                ite--;
            }
            for(auto it:X){
                int val=dp[it];
                rep(i,2) check_min(newdp[i],abs(v[i]-it)+val);
                dp.erase(it);
            }
        }
        // b[0][j]+x >0 b[1][j]-x <0
        // x> -b[0][j] x>b[1][j]
        ite=dp.upper_bound(max(-b[0][j],b[1][j]));
        while (ite!=dp.end()){
            rep(i,2) check_min(newdp[i],abs(v[i]-ite->first)+ite->second);
            ite=dp.erase(ite);
        }
        upd(v[0],newdp[0]);
        upd(v[1],newdp[1]);
        // for(auto it:dp){
            // cout<<j<<":"<<it.first<<" "<<it.second<<endl;
        // }
    }
    int best=INF;
    for(auto it:dp) check_min(best,it.second);
    cout<<ans+best<<endl;
    return 0;
}