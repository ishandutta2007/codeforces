/**
 *    author:  gary
 *    created: 07.02.2022 20:06:33
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
const LL INF=1e18;
typedef pair<int,int> mp;
const int MAXN=202;
LL f[MAXN][MAXN][2],g[MAXN][MAXN][2];
int n,t,carry;
LL a[MAXN],b[MAXN],c[MAXN];
LL sa[MAXN],sb[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>t>>carry;
    rb(i,1,n) cin>>a[i]>>b[i]>>c[i];
    n++;
    a[n]=carry,b[n]=carry,c[n]=INF;
    rep(i,MAXN) rep(j,MAXN) rep(k,2) f[i][j][k]=g[i][j][k]=INF*(i!=0);
    rb(i,1,n) sa[i]=sa[i-1]+a[i],sb[i]=sb[i-1]+b[i];
    rb(i,1,n){
        rb(j,0,t){
            rep(k,2){
                // i
                if(j*b[i]+k*a[i]<=c[i]&&f[i-1][j][k]!=INF){    
                    check_min(f[i][j][k],f[i-1][j][k]);
                    LL need=(sa[i-1]*k+sb[i-1]*j+carry-1)/carry;
                    if(need*carry<=sa[i]*k+sb[i]*j){
                        check_min(g[i][j][k],need); 
                    }
                }
                rb(z,0,j-1){
                    if(g[i][z][k]!=INF){
                        LL rem=sa[i]*k+sb[i]*z-g[i][z][k]*carry;
                        LL need=(max(0ll,rem+(j-z)*b[i]-c[i])+carry-1)/carry;
                        if(need*carry<=rem&&f[i-1][j-z][0]!=INF){
                            check_min(f[i][j][k],g[i][z][k]+f[i-1][j-z][0]+need);
                            LL tmp=(sb[i-1]*(j-z)+carry-1)/carry;
                            LL total=sb[i]*(j-z)+rem-need*carry;
                            if(tmp*carry<=total)
                            check_min(g[i][j][k],g[i][z][k]+need+tmp);
                        }
                    }
                }
            }
        }
    }
    cout<<f[n][t][1]<<endl;
    return 0;
}