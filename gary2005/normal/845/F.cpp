/**
 *    author:  gary
 *    created: 06.09.2021 20:38:51
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
const int MAXN=250;
const int MAXM=15;
char a[MAXN][MAXM];
int n,m;
const int MOD=1e9+7;
int dp[2][MAXM][1<<MAXM][2][2];
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int main(){
    scanf("%d%d",&n,&m);
    if(n>m) rep(i,n) rep(j,m) cin>>a[i][j];
    else {rep(i,n) rep(j,m) cin>>a[j][i];swap(n,m);}
    dp[0][0][0][0][0]=1;
    // rep(i,n){
    //     rep(j,m) cout<<a[i][j];
    //     cout<<endl;
    // }
    rep(i,n){
        memset(dp[(i&1)^1],0,sizeof(dp[(i&1)^1]));
        rep(j,m){
            rep(mask,1<<m){
                rep(f,2){
                    rep(g,2){
                        if(dp[i&1][j][mask][f][g]){
                            int val=dp[i&1][j][mask][f][g];
                            int nmask,nf,ng;
                            ng=g;
                            nmask=mask;
                            nf=f;
                            if(a[i][j]=='x'){
                                if((nmask>>j)&1) nmask^=1<<j;
                                nf=0;
                                if(j!=m-1) add(dp[i&1][j+1][nmask][nf][g],val);
                                else add(dp[(i&1)^1][0][nmask][0][g],val);
                                continue;
                            }
                            if(!g&&!((mask>>j)&1)&&!f){
                                if(j!=m-1) add(dp[i&1][j+1][nmask][nf][1],val);
                                else add(dp[(i&1)^1][0][nmask][0][1],val);
                            }
                            if(((mask>>j)&1)||f){
                                if(j!=m-1) add(dp[i&1][j+1][nmask][nf][g],val);
                                else add(dp[(i&1)^1][0][nmask][0][g],val);
                            }
                            nmask|=1<<j;
                            nf=1;
                            // cout<<n<<" "<<i<<' '<<j<<" "<<nmask<<endl;
                            if(j!=m-1) add(dp[i&1][j+1][nmask][nf][g],val);
                            else add(dp[(i&1)^1][0][nmask][0][g],val);
                        }
                    }
                }
            }
        }
    }
    int answer=0;
    rep(mask,1<<m) rep(f,2) rep(g,2){
        // if(dp[n&1][0][mask][f][g]) cout<<mask<<" "<<f<<' '<<g<<endl;
        add(answer,dp[n&1][0][mask][f][g]);
    } 
    cout<<answer<<endl;
    return 0;
}