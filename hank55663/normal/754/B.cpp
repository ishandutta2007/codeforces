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
#define MXN 10005
#define less Less
char c[4][10];
int X[4]={-1,0,1,-1};
int Y[4]={-1,-1,-1,0};
bool check(){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(c[i][j]=='x'){
                for(int k = 0;k<4;k++){
                    int x=X[k]+i,x2=i-X[k];
                    int y=Y[k]+j,y2=j-Y[k];
                    if(x>=0&&x<4&&y>=0&&y<4&&x2>=0&&x2<4&&y2>=0&&y2<4&&c[x][y]=='x'&&c[x2][y2]=='x'){
                       // printf("%d %d %d %d %d %d %d\n",i,j,k,x,y,x2,y2);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    for(int i = 0;i<4;i++)
        scanf("%s",c[i]);
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(c[i][j]=='.'){
                c[i][j]='x';
                if(check()){
                 //   for(int k=0;k<4;k++)
                   // printf("%s\n",c[k]);
                    printf("YES\n");
                    return 0;
                }
                c[i][j]='.';
            }
        }
    }
    printf("NO\n");
    return 0;
}
/*
1 
2 6 
3 5 
4
*/