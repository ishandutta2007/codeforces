#include<cstdio>
#include<algorithm>
#define N 501
#define inf 10000
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int n,p[N],a[N][N];
inline void upd(int &x,int y){if(y<x)x=y;}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&p[i]);
    rep(i,1,n)rep(j,1,n)a[i][j]=inf;
    rep(i,1,n)a[i][i]=1,a[i][i-1]=1;
    rep(i,1,n)rep(j,1,n-i){
        rep(k,j,i+j)upd(a[j][i+j],a[j][k]+a[k+1][i+j]);
        if(p[j]==p[i+j])upd(a[j][i+j],a[j+1][i+j-1]);
    }
    printf("%d\n",a[1][n]); 
}