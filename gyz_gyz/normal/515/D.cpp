#include<cstdio>
#include<cstdlib>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 2010
#define rt printf("Not unique\n");exit(0);
#define ft(i,j) if((!a[i][j])&&(!s[i][j])){rt}if((!a[i][j])&&(s[i][j]==1))f(i,j);
using namespace std;
const char tc[6]={'.','<','>','^','v','*'};
int a[mx][mx],s[mx][mx],n,m;char x;
void p(int i,int j);
void f(int i,int j){
    s[i-1][j]--;s[i+1][j]--;s[i][j-1]--;s[i][j+1]--;
    if(!a[i-1][j]){a[i][j]=4;a[i-1][j]=3;p(i-1,j);}
    if(!a[i+1][j]){a[i][j]=3;a[i+1][j]=4;p(i+1,j);}
    if(!a[i][j-1]){a[i][j]=2;a[i][j-1]=1;p(i,j-1);}
    if(!a[i][j+1]){a[i][j]=1;a[i][j+1]=2;p(i,j+1);}
}
void p(int i,int j){
    s[i-1][j]--;s[i+1][j]--;s[i][j-1]--;s[i][j+1]--;
    ft(i-1,j)ft(i+1,j)ft(i,j-1)ft(i,j+1)
}
int main(){
    memset(a,-1,sizeof(a));
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("\n");        
        rep(j,1,m){
            scanf("%c",&x);
            if(x=='*')a[i][j]=5;else{a[i][j]=0;
                s[i+1][j]++;s[i-1][j]++;
                s[i][j+1]++;s[i][j-1]++;
            }
        }
    }
    rep(i,1,n)rep(j,1,m){ft(i,j)}
    rep(i,1,n)rep(j,1,m)if(!a[i][j]){rt}
    rep(i,1,n){
        rep(j,1,m)printf("%c",tc[a[i][j]]);
        printf("\n");
    }
}