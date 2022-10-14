/**
 *    author:  gary
 *    created: 11.09.2021 11:11:54
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
int dp[31][21][21][41][41],n,a[5],b[5],c[5],d[5];
int M[30];
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int main(){
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    rep(i,n){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<0) a[i]=-x;
        else b[i]=x;
        if(y<0) c[i]=-y;
        else d[i]=y;
        // cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<' '<<d[i]<<endl;
    }
    rep(i,30) M[i]=(m>>(29-i))&1;
    dp[0][0][0][20][20]=1;
    rep(i,30) rep(j,21) rep(k,21) rb(x,-20,20) rb(y,-20,20) if(dp[i][j][k][x+20][y+20]){
        int val=dp[i][j][k][x+20][y+20];
        // cout<<i<<' '<<j<<' '<<k<<' '<<x<<" "<<y<<' '<<val<<endl;
        rep(mask,1<<n){
            int nj,nk,nx,ny;
            nj=j*2;nx=x*2;
            nk=k*2;ny=y*2;
            nj+=M[i];
            nk+=M[i];
            rep(_,n){
                if((mask>>_)&1){
                    nx+=a[_]-b[_];
                    ny+=c[_]-d[_];
                    nj-=a[_];
                    nk-=c[_];
                }
            }
            check_min(nj,20);
            check_min(nk,20);
            // if(i==28&&j==0&&k==0&&x==0&&y==0){
            //     cout<<bitset<3>(mask)<<" "<<nj<<" "<<nk<<" "<<nx<<" "<<ny<<endl;
            // }
            if(nj>=0&&nk>=0&&abs(nx)<=20&&abs(ny)<=20){
                add(dp[i+1][nj][nk][nx+20][ny+20],val);
            } 
        }
    }
    int answer=0;
    rep(i,21) rep(j,21) add(answer,dp[30][i][j][20][20]);
    add(answer,MOD-1);
    printf("%d\n",answer);
    return 0;
}