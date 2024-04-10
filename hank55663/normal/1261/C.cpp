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
#define MXN 200005
vector<vector<char> > c;
vector<vector<int> > sum;
vector<vector<int> > dis;
vector<vector<char> > ans;
int cal(int a,int b,int c,int d){
    a--;
    b--;
  //  printf("%d %d %d %d\n",sum[c][d],sum[a][b],sum[a][d],sum[b][c]);
    return sum[c][d]+sum[a][b]-sum[a][d]-sum[c][b];
}
int X[8]={-1,-1,-1,0,0,1,1,1};
int Y[8]={-1,0,1,-1,1,-1,0,1};
bool check(int val,int n,int m){
    queue<pii> q;
    dis.clear();
    dis.resize(n+1,vector<int>(m+1,val+1));
    for(int i = 1+val;i<=n-val;i++){
        for(int j=1+val;j<=m-val;j++){
            if(cal(i-val,j-val,i+val,j+val)==(val*2+1)*(val*2+1)){
                q.push(mp(i,j));
                dis[i][j]=0;
              //  printf("%d %d %d\n",val,i,j);
            }
        }
    }
   /* if(q.empty()){
        printf("%d\n",val);
    }*/
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        if(dis[p.x][p.y]==val)continue;
        for(int i = 0;i<8;i++){
            int x=p.x+X[i],y=p.y+Y[i];
            if(dis[x][y]>dis[p.x][p.y]+1){
                dis[x][y]=dis[p.x][p.y]+1;
                q.push(mp(x,y));
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
           // printf("%d",dis[i][j]);
            if(c[i][j]=='.'&&dis[i][j]<=val)return false;
            if(c[i][j]=='X'&&dis[i][j]>val)return false;
        }
      //  printf("\n");
    }
    //printf("!%d\n",val);
    return true;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    c.resize(n+1,vector<char>(m+1));
    ans.resize(n+1,vector<char>(m+1,'.'));
    sum.resize(n+1,vector<int>(m+1,0));
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&c[i][j]);
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
            if(c[i][j]=='X')sum[i][j]++;
        }
    }
    //printf("%d\n",cal(1,1,3,3));
    int Max=1e6,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        if(check(mid,n,m)){
            Min=mid;
        }
        else{
            Max=mid;
        }
     //   printf("\n");
    }
    printf("%d\n",Min);
    int val=Min;
    for(int i = 1+val;i<=n-val;i++){
        for(int j=1+val;j<=m-val;j++){
            if(cal(i-val,j-val,i+val,j+val)==(val*2+1)*(val*2+1)){
              //  q.push(mp(i,j));
                ans[i][j]='X';
     //           dis[i][j]=0;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
}
/*
9 4 
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/