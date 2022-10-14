/**
 *    author:  gary
 *    created: 13.06.2022 00:07:19
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
const int MAXN=1e2+20;
int n,mn[MAXN],cnt[MAXN],fa[MAXN];
int x[MAXN],y[MAXN],d[MAXN][MAXN];
int siz[MAXN];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void merge(int u,int v){
    fa[root(u)]=root(v);
}
const int MOD=998244353;
int dp[MAXN][MAXN];
int fact[MAXN+1],ifact[MAXN+1];
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
}
int inv(int A){return quick(A,MOD-2);}
void genmath(){
    fact[0]=1;
    rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
    ifact[MAXN]=inv(fact[MAXN]);
    rl(i,MAXN-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
}
int comb(int A,int B){
    if(A<0||B<0) return 0;
    if(A<B) return 0;
    return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
}
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void sub(int &A,int B){
    A+=MOD-B;
    if(A>=MOD) A-=MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    genmath();
    cin>>n;
    rb(i,1,n) cin>>x[i]>>y[i];
    rb(i,1,n) rb(j,1,n) d[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
    rb(i,1,n){
        mn[i]=INF;
        cnt[i]=0;
        rb(j,1,n) if(i!=j){
            if(d[i][j]<mn[i]){
                mn[i]=d[i][j];
                cnt[i]=0;
            }
            if(d[i][j]==mn[i]) cnt[i]++;
        }
        fa[i]=i;
    }
    rb(i,1,n) rb(j,1,n) if(d[i][j]==mn[i]&&d[i][j]==mn[j]&&cnt[i]==1&&cnt[j]==1) merge(i,j);
    rb(i,1,n) rb(j,1,n) rb(k,1,n) if(d[i][j]==d[i][k]&&d[i][k]==d[j][k]&&d[i][j]==mn[i]&&mn[i]==mn[j]&&mn[j]==mn[k]&&cnt[i]==2&&cnt[j]==2&&cnt[k]==2) merge(i,j),merge(j,k);
    rb(i,1,n) rb(j,1,n) rb(k,1,n) if(d[i][j]==d[i][k]&&d[i][k]==d[j][k]&&d[i][j]==mn[i]&&mn[i]==mn[j]&&mn[j]==mn[k]&&cnt[i]==3&&cnt[j]==3&&cnt[k]==3)
    rb(l,1,n) if(d[i][j]==d[i][l]&&d[j][l]==d[i][l]&&d[k][l]==d[i][l]&&mn[l]==mn[i]&&cnt[l]==3) merge(i,j),merge(j,k),merge(k,l);
    rb(i,1,n) siz[root(i)]++;
    vector<int> v;
    rb(i,1,n) if(root(i)==i) v.PB(siz[i]);
    dp[0][0]=1;
    rb(i,1,v.size()){
        rb(j,0,n){
            if(dp[i-1][j]){
                add(dp[i][j+v[i-1]],dp[i-1][j]);
                if(v[i-1]!=1)
                add(dp[i][j+1],dp[i-1][j]);
            }
        }
    }
    int ans=0;
    rb(j,1,n){
        add(ans,1ll*dp[v.size()][j]*comb(n,j)%MOD*fact[j]%MOD);
    }
    cout<<ans<<endl;
    return 0;
}