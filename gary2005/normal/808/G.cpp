/**
 *    author:  gary
 *    created: 11.11.2021 20:12:27
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
const int BOUND=1e5;
struct KMP{
    // 1 base , lowercase
    int fail[BOUND];
    int nxt[BOUND][26];// i,j
    void gen(string s){
        memset(fail,0,sizeof(fail));
        int len=s.length();
        s='$'+s;
        rb(i,2,len){
            fail[i]=fail[i-1];
            while(s[fail[i]+1]!=s[i]){
                if(fail[i]==0) break;
                fail[i]=fail[fail[i]];
            }
            if(s[fail[i]+1]==s[i]) fail[i]++;
        }
        memset(nxt,0,sizeof(nxt));
        rb(i,0,len){
            rep(j,26){
                if(i!=len&&'a'+j==s[i+1]) nxt[i][j]=i+1;
                else{
                    nxt[i][j]=nxt[fail[i]][j];
                }
            }
        }
    }
}k1;

int main(){
    string s,t;
    cin>>s>>t;
    k1.gen(t);
    int n,m;
    n=s.length();
    m=t.length();
    s='$'+s;
    t='#'+t;
    vector<vector<int> > dp;
    dp.resize(n+1);
    rb(i,0,n){
        dp[i]=vector<int> (m+1,-INF);
    }
    dp[0][0]=0;
    rb(i,0,n-1){
        rb(j,0,m-1){
            if(dp[i][j]<0) continue;
            if(s[i+1]!='?'){
                int c=s[i+1]-'a';
                if(k1.nxt[j][c]==m){
                    check_max(dp[i+1][k1.fail[m]],dp[i][j]+1);
                }
                else{
                    check_max(dp[i+1][k1.nxt[j][c]],dp[i][j]);
                }
                continue;
            }
            rep(c,26){
                if(k1.nxt[j][c]==m){
                    check_max(dp[i+1][k1.fail[m]],dp[i][j]+1);
                }
                else{
                    check_max(dp[i+1][k1.nxt[j][c]],dp[i][j]);
                }
            }
        }
    }
    int ans=0;
    rb(j,0,m-1) check_max(ans,dp[n][j]);
    cout<<ans<<endl;
    return 0;
}