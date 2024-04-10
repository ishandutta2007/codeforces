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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
#define N 6000005
#define rank Rank
int main(){
    int dis[4900];
    MEMS(dis);
    dis[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x+4<4900&&dis[x+4]==-1){
            dis[x+4]=dis[x]+1;
            q.push(x+4);
        } 
        if(x+9<4900&&dis[x+9]==-1){
            dis[x+9]=dis[x]+1;
            q.push(x+9);
        }
        if(x+49<4900&&dis[x+49]==-1){
            dis[x+49]=dis[x]+1;
            q.push(x+49);
        }
    }
    int n;
    scanf("%d",&n);
    LL ans=0;
  //  for(int i = 0;i<=49;i++)printf("%d %d\n",i,dis[i]);
    for(int i = 0;i<4900;i++){
        if(dis[i]!=-1&&dis[i]<=n){
            ans++;
        //    printf("%d %d\n",i,dis[i]);
        }
    }
    for(int i =4851;i<4900;i++){
        if(dis[i]<=n){
            ans+=n-dis[i];
        }
    }
    printf("%lld\n",ans);
}