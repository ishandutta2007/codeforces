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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
int vis[1<<20];
int main(){
    char c[1000005];
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        int now=0;
        for(int j=i;j>=0;j--){
            if(now&(1<<(c[j]-'a')))break;
            now|=(1<<(c[j]-'a'));
            vis[now]=__builtin_popcount(now);
        }
    }
    for(int i = 0;i<(1<<20);i++){
        for(int j = 0;j<20;j++){
            if((i&(1<<j))==0){
                vis[i|(1<<j)]=max(vis[i|(1<<j)],vis[i]);
            }
        }
    }
    int ans=0;
    for(int i = 0;i<(1<<20);i++){
        ans=max(ans,vis[i]+vis[((1<<20)-1)^i]);
    }
    printf("%d\n",ans);
    return 0;
}