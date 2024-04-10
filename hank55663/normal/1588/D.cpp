#include<bits/stdc++.h>
#pragma optimize(Ofast)
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
vector<int> v[10][52];
int dp[1<<10][52];
pii from[1<<10][52];
int DP(int x,int y,int n){
    if(dp[x][y]!=-1)return dp[x][y];
    dp[x][y]=1;
    from[x][y]=mp(-1,-1);
    for(int j = 0;j<52;j++){
        int tar=0;
        int ok=1;
        for(int i = 0;i<n;i++){
            int vv=((x&(1<<i))!=0);
            int loc=v[i][y][vv];
            if(v[i][j].empty())ok=0;
            else if(v[i][j].size()==1){
                if(v[i][j][0]>=loc)ok=0;
            }
            else{
                if(v[i][j][0]>=loc)ok=0;
                else if(v[i][j][1]>=loc);
                else tar+=(1<<i);
            }
        }
        if(!ok)continue;
        if(dp[x][y]<DP(tar,j,n)+1){
            dp[x][y]=DP(tar,j,n)+1;
            from[x][y]=mp(tar,j);
        }
    }
    return dp[x][y];
}
void solve(){
    MEMS(dp);
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<52;j++)v[i][j].clear();
    }
    for(int i = 0;i<n;i++){
        char c[155];
        scanf("%s",c);
        
        for(int j = 0;c[j]!=0;j++){
            if(c[j]>='a'){
                v[i][c[j]-'a'+26].pb(j);
            }
            else{
                v[i][c[j]-'A'].pb(j);
            }
        }
    }
    int Max=0;
    pii p=mp(-1,-1);
    for(int i = 0;i<(1<<n);i++){
        for(int j = 0;j<52;j++){
            int ok=1;
            for(int k=0;k<n;k++){
                int vv=((i&(1<<k))!=0);
                if(vv>=v[k][j].size())ok=0;
            }
            if(ok){
                DP(i,j,n);
                if(dp[i][j]>Max){
                    Max=dp[i][j];
                    p=mp(i,j);
                }
            }
        }
    }
    vector<char> v;
    while(p!=mp(-1,-1)){
        if(p.y>=26)v.pb(p.y-26+'a');
        else v.pb(p.y+'A');
        p=from[p.x][p.y];
    }
    reverse(v.begin(),v.end());
    printf("%d\n",Max);
    for(auto it:v)printf("%c",it);
    printf("\n");
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/