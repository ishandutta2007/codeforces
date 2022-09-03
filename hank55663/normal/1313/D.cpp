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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 10000
int val[200005];
vector<int> v[200005];
int belong[200005][8];
//vector<int> st[200005];
int dp[200005][256];
int main(){
    int n,M,k;
    scanf("%d %d %d",&n,&M,&k);
    pii p[100005];
    map<int,int> m;
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        m[x-1];
        m[y];
    }
    int index=0;
    for(auto& it:m){
        it.y=++index;
        val[index]=it.x;
    }
    for(int i = 0;i<n;i++){
        p[i].x=m[p[i].x-1]+1;
        p[i].y=m[p[i].y];
        for(int j=p[i].x;j<=p[i].y;j++){
            if(j!=p[i].y)
            belong[j][v[j].size()]=v[j+1].size();
            else
            belong[j][v[j].size()]=-1;
            v[j].pb(i);
            
        }
  //      st[p[i].x].pb(i);
    }
    int ans=0;
    for(int i = 1;i<=index;i++){
        int vala=0,valb=0;
        for(int j=0;j<v[i].size();j++){
            if(p[v[i][j]].x!=i)vala+=(1<<j);
            else valb+=(1<<j);
        }
       // printf("%d %d\n",vala,valb);
        for(int j = vala;;j=(j-1)&vala){
            for(int k=valb;;k=(k-1)&valb){
                dp[i][j+k]=max(dp[i][j+k],dp[i][j]+((__builtin_popcount(j+k)&1)==1 ? val[i]-val[i-1] : 0));
                if(k==0)
                break;
            }
            if(j==0)
            break;
        }
        for(int j=0;j<(1<<v[i].size());j++){
            int Val=0;
            for(int k=0;k<v[i].size();k++){
                if(j&(1<<k)){
                    if(belong[i][k]!=-1){
                        Val+=(1<<belong[i][k]);
                    }
                }
            }
            ans=max(ans,dp[i][j]);
            dp[i+1][Val]=max(dp[i+1][Val],dp[i][j]);
           // printf("%d %d %d\n",val[i],j,dp[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}