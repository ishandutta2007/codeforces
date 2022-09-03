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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
char c[55][55];
int n,m;
vector<pii> stk;
bool dfs(int x,int y){
    stk.pb(mp(x,y));
    c[x][y]='*';
    bool res=true;
    if(x==0||x==n-1||y==0||y==m-1)res=false;
    int X[4]={0,0,1,-1};
    int Y[4]={1,-1,0,0};
    for(int i = 0;i<4;i++){
        int xx=x+X[i],yy=y+Y[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&c[xx][yy]=='.'){
            res&=dfs(xx,yy);
        }
    }    
    return res;
}
bool cmp(const vector<pii>  &a,const vector<pii> &b){
    return a.size()<b.size();
}
int main(){
    int k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
    }
    vector<vector<pii> > lake;
    vector<vector<pii> > tmp;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(c[i][j]=='.'){
                if(dfs(i,j)){
                    lake.pb(stk);
                }
                else{
                    tmp.pb(stk);
                }
                stk.clear();
            }
        }
    }
  //  printf("%d\n",lake.size());
    sort(lake.begin(),lake.end(),cmp);
    for(int i = 0;i<k;i++){
        for(auto it:lake.back()){
            c[it.x][it.y]='.';
        }
        lake.pop_back();
    }
    for(auto it:tmp){
        for(auto iit:it){
            c[iit.x][iit.y]='.';
        }
    }
    int sum=0;
    for(auto it:lake){

        sum+=it.size();
    }
    printf("%d\n",sum);
    for(int i =0;i<n;i++)
        printf("%s\n",c[i]);
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */