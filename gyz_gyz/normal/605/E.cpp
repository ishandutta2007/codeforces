#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1001
#define inf 100000000
using namespace std;
double a[N][N],p[N],t[N],w;int n,s,v[N];
inline double f(int x){
    if(t[x]==1)return inf;
    return (p[x]+1)/(1-t[x]);
}
int main(){
    scanf("%d",&n);
    rep(i,1,n)rep(j,1,n){
        scanf("%lf",&a[i][j]);a[i][j]/=100;
    }
    rep(i,1,n-1)t[i]=1;p[n]=-1;
    rep(i,1,n){
        s=0;w=inf;
        rep(j,1,n)if(!v[j]&&f(j)<w)w=f(j),s=j;
        if(!s)break;v[s]=1;
        rep(j,1,n)if(!v[j]){
            p[j]+=w*t[j]*a[j][s];t[j]*=(1-a[j][s]);
        }
    }
    printf("%.10lf\n",f(1));
}