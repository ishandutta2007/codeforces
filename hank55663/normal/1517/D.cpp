#include<bits/stdc++.h>
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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MAXK 2500
int dis[505][505][15];
int vis[505][505][15];
int val1[505][505];
int val2[505][505];
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m-1;j++)scanf("%d",&val1[i][j]);
    }
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<m;j++)scanf("%d",&val2[i][j]);
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int a=0;a<k;a++)dis[i][j][a]=1e9;
        }
    }
    int cnt=0;
    vector<pii> q,q2;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cnt++;
            if(k%2==1){
                printf("-1 ");
            }
            else{
                q.pb(mp(i,j));
                dis[i][j][0]=0;
                for(int a=0;a<k/2;a++){
                   // vector<pii> tmp;
                    for(auto p:q){  
                      //  pii p=q.front();
                      //  q.pop();
                        //v.pb(mp(a,p));
                        if(p.x>0){
                            if(vis[p.x-1][p.y][a+1]!=cnt){
                                vis[p.x-1][p.y][a+1]=cnt;
                                 dis[p.x-1][p.y][a+1]=dis[p.x][p.y][a]+val2[p.x-1][p.y];
                                q2.pb(mp(p.x-1,p.y)); 
                            }
                            dis[p.x-1][p.y][a+1]=min(dis[p.x-1][p.y][a+1],dis[p.x][p.y][a]+val2[p.x-1][p.y]);
                        }
                        if(p.y>0){
                            if(vis[p.x][p.y-1][a+1]!=cnt){
                                vis[p.x][p.y-1][a+1]=cnt;
                                 dis[p.x][p.y-1][a+1]=dis[p.x][p.y][a]+val1[p.x][p.y-1];
                                q2.pb(mp(p.x,p.y-1)); 
                            } 
                            dis[p.x][p.y-1][a+1]=min(dis[p.x][p.y-1][a+1],dis[p.x][p.y][a]+val1[p.x][p.y-1]);
                        }
                        if(p.x<n-1){
                            if(vis[p.x+1][p.y][a+1]!=cnt){
                                vis[p.x+1][p.y][a+1]=cnt;
                                 dis[p.x+1][p.y][a+1]=dis[p.x][p.y][a]+val2[p.x][p.y];
                                q2.pb(mp(p.x+1,p.y)); 
                            }
                             dis[p.x+1][p.y][a+1]=min(dis[p.x+1][p.y][a+1],dis[p.x][p.y][a]+val2[p.x][p.y]);
                        }
                        if(p.y<m-1){
                            if(vis[p.x][p.y+1][a+1]!=cnt){
                                vis[p.x][p.y+1][a+1]=cnt;
                                 dis[p.x][p.y+1][a+1]=dis[p.x][p.y][a]+val1[p.x][p.y];
                                q2.pb(mp(p.x,p.y+1)); 
                            }
                             dis[p.x][p.y+1][a+1]=min(dis[p.x][p.y+1][a+1],dis[p.x][p.y][a]+val1[p.x][p.y]);
                        }
                    }
                    swap(q,q2);
                    q2.clear();
                   // v.pb(tmp);
                }
                int ans=1e9;
                
                for(auto p:q){
                   // pii p=q.front();
                   // q.pop();
                    vis[p.x][p.y][k/2]=0;
                    ans=min(ans,dis[p.x][p.y][k/2]);
                   //  printf("%d %d %d\n",p.x,p.y,dis[p.x][p.y][k/2]);
                    dis[p.x][p.y][k/2]=1e9;
                   
                }
                q.clear();
                printf("%d ",ans*2);
            }
        }
        printf("\n");
    }
}
int main(){
    int t=1;00000;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/