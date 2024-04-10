#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 100001
using namespace std;
int n,m,x,y,z,f[mx],r[mx],p,ans;
void gf(int x){
    if(f[x]!=x)gf(f[x]);
    r[x]^=r[f[x]]^1;f[x]=f[f[x]];
}
int main(){
    scanf("%d%d",&n,&m);ans=1;
    rep(i,1,n)f[i]=i;
    rep(i,1,m){
        scanf("%d%d%d",&x,&y,&z);
        gf(x);gf(y);
        if(f[x]!=f[y]){
            r[f[y]]=r[y]^z^1;f[f[y]]=x;
        }else if(r[x]^r[y]==z){
            printf("0\n");return 0;
        }
    }
    rep(i,1,n)if(f[i]==i)p++;
    rep(i,2,p)ans=ans*2%1000000007;
    printf("%d\n",ans);
}