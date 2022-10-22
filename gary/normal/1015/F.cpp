/**
 *    author:  gary
 *    created: 06.10.2021 14:11:04
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
const int B=200;
const int MOD=1e9+7;
int n;
string s;
int dp[B+1][B+1][B+1];
int nex[B+1][2];
char c[2]={'(',')'};
int val[2]={1,-1};
int main(){
    cin>>n>>s;
    nex[s.length()][0]=nex[s.length()][1]=s.length();
    rb(i,0,s.length()-1){
        rep(j,2){
            if(c[j]==s[i]){
                nex[i][j]=i+1;
            }
            else{
                string s2;
                rep(k,i) s2.PB(s[k]);
                s2.PB(c[j]);
                rep(k,i+1){
                    bool ok=0;
                    rep(l,k){
                        if(s[k-1-l]==s2[s2.length()-1-l]);
                        else{
                            ok=1;
                        }
                    }
                    if(!ok) nex[i][j]=k;
                }
            }
        }
    }
    dp[0][0][0]=1;
    rb(i,0,2*n-1) rb(j,0,s.length()) rb(k,0,i) if(dp[i][j][k]) {
        rep(nx,2) if(k+val[nx]>=0) (dp[i+1][nex[j][nx]][k+val[nx]]+=dp[i][j][k])%=MOD;
    }
    cout<<dp[2*n][s.length()][0]<<endl;
    return 0;
}