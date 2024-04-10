#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define N 200005
#define rank Rank
#define index Index
vector<int> row[10005],col[10005];
int visr[10005],visc[10005];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    map<pii,int> M;
    pii p[10005];
    for(int i =0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        row[x].pb(i);
        row[x+1].pb(i);
        row[x-1].pb(i);
        col[y].pb(i);
        col[y+1].pb(i);
        col[y-1].pb(i);
        M[mp(x,y)]=i;
        p[i]=mp(x,y);
    }
    int st=M[mp(1,1)];
    int dis[10005];
    fill(dis,dis+k+1,1e9);
    dis[st]=0;
    queue<int> q,q2;
    q.push(st);
    int ndis=0;
    while(!q.empty()){
        while(!q.empty()){
            int a=q.front();
            q.pop();
            int X[4]={0,0,1,-1};
            int Y[4]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int x=p[a].x+X[i];
                int y=p[a].y+Y[i];
                if(M.find(mp(x,y))!=M.end()){
                    int k=M[mp(x,y)];
                    if(dis[k]>ndis){
                        dis[k]=ndis;
                        q.push(k);
                    }
                }
            }
            for(int k = -1;k<=1;k++){
                if(!visr[p[a].x+k]){
                    visr[p[a].x+k]=1;
                    for(auto it:row[p[a].x+k]){
                        if(dis[it]>ndis+1){
                            q2.push(it);
                            dis[it]=ndis+1;
                        }
                    }
                }
                if(!visc[p[a].y+k]){
                    visc[p[a].y+k]=1;
                    for(auto it:col[p[a].y+k]){
                        if(dis[it]>ndis+1){
                            q2.push(it);
                            dis[it]=ndis+1;
                        }
                    }
                }
            }
        }
        ndis++;
        while(!q2.empty()){
            int x=q2.front();
            q2.pop();
            if(dis[x]==ndis){
                q.push(x);
            }
        }
    }
    int ans=1e9;
    for(int i=0;i<k;i++){
     //   printf("%d\n",dis[i]);
        if(p[i].x==n||p[i].x==n-1){
            ans=min(ans,dis[i]+1);
        }
        if(p[i].y==m||p[i].y==m-1){
            ans=min(ans,dis[i]+1);
        }
        if(p[i].x==n&&p[i].y==m){
            ans=min(ans,dis[i]);
        }
    }
    if(ans==1e9)ans=-1;
    printf("%d\n",ans);
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
11010101
*/