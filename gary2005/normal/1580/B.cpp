/**
 *    author:  gary
 *    created: 30.09.2021 18:03:44
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
int MOD;
int n,m,k;
int f[101][101][101],c[101][101],fact[101],mx[101][101];
int main(){
    rb(i,0,100) c[i][0]=1;
    cin>>n>>m>>k>>MOD;
    rb(i,1,100) rb(j,1,100) (c[i][j]=c[i-1][j]+c[i-1][j-1])%=MOD;
    fact[0]=1;
    rb(i,1,100) fact[i]=1ll*fact[i-1]*i%MOD;
    rb(j,0,100) f[0][j][0]=1;
    rb(i,1,n) rb(j,1,100){
        if(j==1){
            f[i][j][1]=fact[i];
            mx[i][j]=1;
            continue;
        }
        if(j>i){
            f[i][j][0]=fact[i];
            continue;
        }
        rb(k,0,i){
            rb(x,0,i-1){
                int y=i-1-x;
                rb(A,max(0,k-mx[y][j-1]),min(k,mx[x][j-1])){
                    if(y<j-1) A=k;
                    {
                        int B=k-A;
                        f[i][j][k]+=1ll*f[x][j-1][A]*f[y][j-1][B]%MOD*c[x+y][x]%MOD;
                        if(f[i][j][k]>=MOD)
                        f[i][j][k]-=MOD;
                    }
                    if(x<j-1) break;
                }
            }
            if(f[i][j][k]) mx[i][j]=k;
        }
    }
    cout<<f[n][m][k];
    return 0;
}