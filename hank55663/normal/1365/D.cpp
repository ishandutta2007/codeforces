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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        char c[55][55];
        int vis[55][55];
        MEM(vis);
        MEM(c);
        for(int i = 1;i<=n;i++){
            scanf("%s",c[i]+1);
        }
        int ok=1;
        int cnt=0;
        int X[4]={0,0,1,-1};
        int Y[4]={1,-1,0,0};
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(c[i][j]=='B'){
                    for(int k=0;k<4;k++){
                        int x=i+X[k],y=j+Y[k];
                        if(x>=1&&x<=n&&y>=1&&y<=m){
                            if(c[x][y]=='G')ok=0;
                            if(c[x][y]=='.')c[x][y]='#';
                        }
                        
                    }
                }
                if(c[i][j]=='G')cnt++;
            }
        }
        if(c[n][m]!='.'&&c[n][m]!='G')ok=0;
        if(c[n][m]=='#'&&!cnt)ok=1;
        queue<pii> q;
        q.push(mp(n,m));
        vis[n][m]=1;
        while(!q.empty()){
            pii p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=p.x+X[i],y=p.y+Y[i];
                if(vis[x][y])continue;
                if(c[x][y]=='.'){
                    vis[x][y]=1;
                    q.push(mp(x,y));
                }
                if(c[x][y]=='G'){
                     vis[x][y]=1;
                    q.push(mp(x,y));
                    cnt--;
                }
            }
        }
        if(cnt||!ok){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
}
/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/