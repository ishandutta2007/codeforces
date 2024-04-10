/**
 *    author:  gary
 *    created: 25.09.2021 14:44:07
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
const int MAXN=20;
int n,m;
LL k;
LL a[MAXN][MAXN];
LL answer=0;
map<pair<mp,LL> ,int > M;
void dfs1(int x,int y,int step,LL val=0){
    val^=a[x][y];
    if(step==0){
        M[II(II(x,y),val)]++;
        return ;
    }
    if(x!=n-1)
        dfs1(x+1,y,step-1,val);
    if(y!=m-1)
        dfs1(x,y+1,step-1,val);
}
void dfs2(int x,int y,int step,LL val=0){
    if(step==0){
        if(M.find(II(II(x,y),val^k))!=M.end())
        answer+=M[II(II(x,y),val^k)];
        return ;
    }
    val^=a[x][y];
    if(x)
        dfs2(x-1,y,step-1,val);
    if(y)
        dfs2(x,y-1,step-1,val);
}
int main(){
    cin>>n>>m>>k;
    rep(i,n) rep(j,m) cin>>a[i][j];
    int step=n-1+m-1;
    dfs1(0,0,step/2);
    dfs2(n-1,m-1,step-step/2);
    cout<<answer<<endl;
    return 0;
}