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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 200005
int main(){
    vector<string> v;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        char c[1000005];
        scanf("%s",c);
        v.pb(string(c));
    }
    vector<vector<int> > vis(n,vector<int>(m,0));
    queue<pii> q;
    q.push(mp(0,0));
    while(!q.empty()){
        pii p =q.front();
        q.pop();
        int x=p.x+1,y=p.y;
        if(x<n&&!vis[x][y]&&v[x][y]=='.'){
            vis[x][y]=1;
            q.push(mp(x,y));
        }
        x=p.x,y=p.y+1;
        if(y<m&&!vis[x][y]&&v[x][y]=='.'){
            vis[x][y]=1;
            q.push(mp(x,y));
        }
    }
    if(n==1||m==1){
        int ans=1;
        for(auto it:v){
            for(auto c:it){
                if(c=='#')
                    ans=0;
            }
        }
        printf("%d\n",ans);
    }
    else{
        for(int i = 0;i<n;i++){
            for(int j  =0;j<m;j++){
                if(!vis[i][j])
                    v[i][j]='#';
            }
        }
        queue<pii> q,q1;
        vector<vector<int> > dis(n,vector<int>(m,1e9));
        for(int i = 1;i<m;i++){
            if(v[0][i]=='.'){
                q1.push(mp(0,i));
                dis[0][i]=1;
            }
            else{
                q.push(mp(0,i));
                dis[0][i]=0;
            }
        }
        for(int i = 0;i<n-1;i++){
            if(v[i][m-1]=='.'){
                q1.push(mp(i,m-1));
                dis[i][m-1]=1;
            }
            else{
                q.push(mp(i,m-1));
                dis[i][m-1]=0;
            }
        }
        int now=0;
        int X[8]={-1,-1,-1,0,0,1,1,1};
        int Y[8]={-1,0,1,-1,1,-1,0,1};
        while(!q.empty()||!q1.empty()){
            while(!q.empty()){
                pii p=q.front();
               // printf("%d %d %d\n",p.x,p.y,now);
                //getchar();
                q.pop();
                if(dis[p.x][p.y]!=now)continue;
                if(p.x==n-1||p.y==0){
                    printf("%d\n",now);
                    return 0;
                }

                for(int i = 0;i<8;i++){
                    int x=p.x+X[i],y=p.y+Y[i];
                    if(x>=0&&x<n&&y>=0&&y<m&&!(x==0&&y==0)&&!(x==n-1&&y==m-1)){
                        if(v[x][y]=='#'&&dis[x][y]>now){
                            dis[x][y]=now;
                            q.push(mp(x,y));
                        }
                        if(v[x][y]=='.'&&dis[x][y]>now+1){
                            dis[x][y]=now+1;
                            q1.push(mp(x,y));
                        }
                    }
                } 
            }
            while(!q1.empty()){
                q.push(q1.front());
                q1.pop();
            }
            now++;
        }
    }
}