/**
 *    author:  gary
 *    created: 14.05.2022 18:13:09
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
const int MOD=998244353;
const int MAXN=1e3+10;
int n;
string s;
int pw[18][MAXN];
int dp[1<<17][18];
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int pre[MAXN],suf[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s;
    rb(i,1,17){
        pw[i][0]=1;
        rb(j,1,n) pw[i][j]=1ll*pw[i][j-1]*i%MOD;
    }
    rep(i,n) pre[i+1]=suf[i+1]=(s[i]=='?');
    rb(i,1,n) pre[i]+=pre[i-1];
    rl(i,n,1) suf[i]+=suf[i+1];
    rep(i,n){
        int l=i,r=i;
        int cnt=(s[i]=='?');
        int need=0;
        while (l>=0&&r<n){
            rb(j,1,17) add(dp[need][j],pw[j][cnt+pre[l]+suf[r+2]]);
            l--;
            r++;
            if(l>=0&&r<n){
                if((s[l]=='?')+(s[r]=='?')==0){
                    if(s[l]!=s[r]) break;
                }else
                if((s[l]=='?')+(s[r]=='?')==1){
                    char c=(s[l]=='?'? s[r]:s[l]);
                    need|=1<<(c-'a');
                }else
                if((s[l]=='?')+(s[r]=='?')==2){
                    cnt++;
                }
            }
            else break;
        }
    }
    rep(i,n){
        int l=i+1,r=i;
        int cnt=0;
        int need=0;
        while (true){
            if(l<=r)
            rb(j,1,17) add(dp[need][j],pw[j][cnt+pre[l]+suf[r+2]]);
            l--;
            r++;
            if(l>=0&&r<n){
                if((s[l]=='?')+(s[r]=='?')==0){
                    if(s[l]!=s[r]) break;
                }else
                if((s[l]=='?')+(s[r]=='?')==1){
                    char c=(s[l]=='?'? s[r]:s[l]);
                    need|=1<<(c-'a');
                }else
                if((s[l]=='?')+(s[r]=='?')==2){
                    cnt++;
                }
            }
            else break;
        }
    }
    rb(j,1,17){
        rep(k,17){
            rep(mask,1<<17) if((mask>>k)&1)
            add(dp[mask][j],dp[mask^(1<<k)][j]);
        }
    }
    int q;
    cin>>q;
    while (q--){
        int k;
        string s;
        cin>>s;
        k=s.length();
        int mask=0;
        rep(j,k){
            char c=s[j];
            mask|=1<<(c-'a');
        }
        cout<<dp[mask][k]<<endl;
    }
    return 0;
}