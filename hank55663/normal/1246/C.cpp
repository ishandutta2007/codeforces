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
#define MXN 205
int val[2][2005][2005];
const int mod=1e9+7;
void add_x(int x,int y,int k){
    //printf("x%d %d %d\n",x,y,k);
    for(int i = x;i<2005;i+=i&-i){
        val[0][i][y]+=k;
        val[0][i][y]%=mod;
    }
}
void add_y(int x,int y,int k){
   // printf("y%d %d %d\n",x,y,k);
    for(int i = y;i<2005;i+=i&-i){
        val[1][x][i]+=k;
        val[1][x][i]%=mod;
    }
}
LL queryx(int x,int y){
    LL res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=val[0][i][y];
    }
    return res%mod;
}
LL queryy(int x,int y){
    LL res=0;
    for(int i = y;i>0;i-=i&-i){
        res+=val[1][x][i];
    }
    return res%mod;
}
int sum[2005][2005];
char c[2005][2005];
int query(int x1,int y1,int x2,int y2){
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    if(n==1&&m==1){
        printf("1\n");
        return 0;
    }
    for(int i = 1;i<=n;i++){
        scanf("%s",c[i]+1);
        for(int j=1;j<=m;j++){
            if(c[i][j]=='R'){
                sum[i][j]++;
            }
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int x=query(1,1,1,m);
    add_y(1,2,1);
    add_y(1,m-x+1,-1);
    x=query(1,1,n,1);
    add_x(2,1,1);
    add_x(n-x+1,1,-1);
  //  printf("%d %d %d\n",queryy(1,1),queryy(1,2),queryy(1,3));
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1)continue;
            int x=queryy(i,j);
            int r=query(i+1,j,n,j);
            add_x(i+1,j,x);
            add_x(n-r+1,j,-x);
            x=queryx(i,j);
            r=query(i,j+1,i,m);
            add_y(i,j+1,x);
            add_y(i,m-r+1,-x);
        }
    }
    printf("%lld\n",(queryx(n,m)+queryy(n,m))%mod);
}
/*
0
10
20
30
40

4+3+3+4+3+2+2+1
13:00
11:

11:24
11:48
12:12
12:36
13:00
13:24
13:48
14:12
14:36
*/