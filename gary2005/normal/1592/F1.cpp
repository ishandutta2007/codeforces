/**
 *    author:  gary
 *    created: 03.10.2021 22:33:45
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
const int MAXN=505;
int n,m;
char c[MAXN][MAXN];
bool a[MAXN][MAXN],b[MAXN][MAXN];
int solve(int i,int j){
    if(i<=0) return 0;
    if(j<=0) return 0;
    return b[i][j]^b[i+1][j]^b[i+1][j+1]^b[i][j+1];
}
int main(){
    cin>>n>>m;
    rb(i,1,n) rb(j,1,m) cin>>c[i][j],a[i][j]=(c[i][j]=='B');
    int ans=0;
    rb(i,1,n) rb(j,1,m) ans+=(a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1]);
    rl(l,n,1){
        int tmp=0;
        rb(i,1,n) rb(j,1,m) tmp+=(a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1]);
        rb(i,1,n) rb(j,1,m) b[i][j]=a[i][j]; 
        rl(j,m,1){
            rl(k,n,l){
                tmp-=solve(k-1,j-1);
                tmp-=solve(k-1,j);
                tmp-=solve(k,j-1);
                tmp-=solve(k,j);
                b[k][j]^=1;
                tmp+=solve(k-1,j-1);
                tmp+=solve(k-1,j);
                tmp+=solve(k,j-1);
                tmp+=solve(k,j);
            }
            check_min(ans,tmp+3);
        }
    }
    cout<<ans<<endl;
    return 0;
}