#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int X[4]={1,-1,0,0};
int Y[4]={0,0,1,-1};
int X2[8]={-1,-1,-1,0,0,1,1,1};
int Y2[8]={-1,0,1,-1,1,-1,0,1};
pii p[10020];
int a[505][505];
int vis[10020];
int print;
int aa[4][4]={4,3,6,12,7,5,9,15,14,1,11,10,13,8,16,2};
int go(int dir,int *X,int *Y,int n){
    int now=1;
    int x,y;
    tie(x,y)=p[now];
    int cnt=1;
    int res=0;
    MEM(vis);
    vis[1]=1;
    
    while(cnt!=n*n){
      //  printf("%d %d\n",x,y);
        int Min=1e9;
        for(int i = 0;i<dir;i++){
            for(int j=1;;j++){
                int xx=x+X[i]*j,yy=y+Y[i]*j;
                
                if(xx>=0&&xx<n&&yy>=0&&yy<n){
                   // printf("? %d %d %d\n",xx,yy,a[xx][yy]);
                    if(!vis[a[xx][yy]]){
                        Min=min(Min,a[xx][yy]);
                    }
                }
                else{
                    break;
                }
            }
        }
        if(Min==1e9){
            res++;
            for(int i = 1;i<=n*n;i++){
                if(!vis[i]){
                    vis[i]=1;
                    tie(x,y)=p[i];
                    if(print)
                    printf("!%d ",i);
                    break;
                }
            }
        }
        else{
            tie(x,y)=p[Min];
            vis[Min]=1;
           if(print)
            printf("%d ",Min);
        }
        cnt++;
    }
    if(print)
    printf("\n");
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    if(n<=2){
        printf("-1\n");
        return 0;
    }
    else if(n==3){
        printf("1 2 4\n5 3 8\n9 6 7\n");
        return 0;
    }
    else if(n==4){
        for(int i =0;i<4;i++){
            for(int j=0;j<4;j++){
                printf("%d ",aa[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    //int a[505][505];
    int now=1;
    //int cnt=0;
    for(int i = n-1;i>=5;i--){
        if(i%2==0){
            for(int j=0;j<i;j++)a[i][j]=now++;
            for(int j=i;j>=0;j--)a[j][i]=now++;
        }
        else{
            for(int j=0;j<=i;j++)a[j][i]=now++;
            for(int j=i-1;j>=0;j--)a[i][j]=now++;
        }
    }
    a[4][0]=now++;
    a[4][1]=now++;
    a[4][2]=now++;
    a[4][3]=now++;
    a[4][4]=now++;
    a[3][4]=now++;
    a[1][4]=now++;
    a[0][4]=now++;
    a[2][4]=now;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            a[i][j]=aa[i][j]+now;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
           // p[a[i][j]]=mp(i,j);
        }
        printf("\n");
    }
   // print=1;
   // printf("%d %d\n",go(4,X,Y,n),go(8,X2,Y2,n));
 /*   vector<int> v;
    for(int i = 1;i<=9;i++){
        v.pb(i);
    }
    do{
        for(int i = 0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j]=v[i*3+j];
                p[a[i][j]]=mp(i,j);
            }
        }
        if(go(8,X2,Y2,3)>go(4,X,Y,3)){
            print=1;
            printf("%d\n",go(8,X2,Y2,3));
            printf("%d\n",go(4,X,Y,3));
            for(int i = 0;i<3;i++){
                for(int j=0;j<3;j++){
                    printf("%d ",a[i][j]);
                }
                printf("\n");
            }
            break;
        }
    }while(next_permutation(v.begin(),v.end()));*/
    
    /*for(int i=  0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&a[i][j]);
            p[a[i][j]]=mp(i,j);
        }
    }
    for(int i = 0;i<4;i++){
        for(int j =0;j<4;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/
    //rintf("%d\n",go(8,X2,Y2,4));
    //printf("%d\n",go(4,X,Y,4));//,go(8,X2,Y2,4));
}
/*

*/