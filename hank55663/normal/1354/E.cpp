#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int color[5005];
int tot[10005];
vector<int> v[5005];
bool dfs(int x,int col){
    color[x]=col;
    tot[col]++;
    int ok=1;
    for(auto it:v[x]){
        if(color[it]==-1){
            ok&=dfs(it,col^1);
        }
        else{
            if(color[it]==col)return false;
        }
    }
    return ok;
}
int dp[10005][5005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    MEMS(color);
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    int cnt=0;
    for(int i = 1;i<=n;i++){
        if(color[i]==-1){
            if(!dfs(i,cnt)){
                printf("NO\n");
                return 0;
            }
            cnt+=2;
        }
    }
    dp[0][0]=1;
    for(int i = 0;i<cnt;i+=2){
        for(int j=0;j<=n;j++){
            if(!dp[i][j])continue;
            dp[i+2][j+tot[i]]|=dp[i][j];
            dp[i+2][j+tot[i+1]]|=dp[i][j];
        }
    }
    if(dp[cnt][b]){
        int now=b;
        int bln[10005];
        MEM(bln);
        for(int i=cnt-2;i>=0;i-=2){
            if(dp[i][now-tot[i]]){
                bln[i]=1;
                now=now-tot[i];
            }
            else{
                bln[i+1]=1;
                now=now-tot[i+1];
            }
        }
        vector<int> v1,v2;
        for(int i = 1;i<=n;i++){
            if(bln[color[i]])v2.pb(i);
            else v1.pb(i);
        }
        char ans[5005];
        MEM(ans);
        for(auto it:v2)ans[it]='2';
        for(int i = 0;i<v1.size();i++){
            if(i<a)ans[v1[i]]='1';
            else ans[v1[i]]='3';
        }
        printf("YES\n%s\n",ans+1);
    }
    else{
        printf("NO\n");
    }
}  

/*
C[i][j]=C[i>>1][j]
1000

1001
0000
0001
1000
1001
*/