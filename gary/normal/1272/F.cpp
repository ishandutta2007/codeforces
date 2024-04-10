/**
 *    author:  gary
 *    created: 01.10.2021 14:09:29
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
int dp[201][201][601];
tuple<bool,bool,bool> pre[201][201][601];
char bra[2]={'(',')'};
void run(int i,int j,int k){
    if(i==0&&j==0&&k==0) return ;
    int ni,nj,nk;
    tie(ni,nj,nk)=pre[i][j][k];
    char c=bra[nk];
    ni=i-ni;
    nj=j-nj;
    nk=k-(nk==0? 1:-1);
    run(ni,nj,nk);
    cout<<c;
}
int main(){
    string s,t;
    cin>>s>>t;
    memset(dp,63,sizeof(dp));
    dp[0][0][0]=0;
    int n,m;
    n=s.length();
    m=t.length();
    rb(i,0,n){
        rb(j,0,m){
            rb(k,0,600){
                if(dp[i][j][k]!=INF){
                    // cout<<i<<' '<<j<<' '<<k<<" "<<m<<endl;
                    rep(f,2){
                        int nxi=i,nxj=j,nxk;
                        if(i!=n&&bra[f]==s[i]) nxi=i+1;
                        if(j!=m&&bra[f]==t[j]) nxj=j+1;
                        nxk=k+(f==0? 1:-1);
                        if(nxk<=600&&nxk>=0&&dp[i][j][k]+1<dp[nxi][nxj][nxk]){
                            dp[nxi][nxj][nxk]=dp[i][j][k]+1;
                            pre[nxi][nxj][nxk]=make_tuple(nxi>i,nxj>j,f);
                        }
                    }
                }
            }
            rl(k,600,0){
                if(dp[i][j][k]!=INF){
                    rep(f,2){
                        int nxi=i,nxj=j,nxk;
                        if(i!=n&&bra[f]==s[i]) nxi=i+1;
                        if(j!=m&&bra[f]==t[j]) nxj=j+1;
                        nxk=k+(f==0? 1:-1);
                        if(nxk<=600&&nxk>=0&&dp[i][j][k]+1<dp[nxi][nxj][nxk]){
                            dp[nxi][nxj][nxk]=dp[i][j][k]+1;
                            pre[nxi][nxj][nxk]=make_tuple(nxi>i,nxj>j,f);
                        }
                    }
                }
            }
        }
    }
    run(n,m,0);
    return 0;
}