#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 2000
using namespace std;
int n,m,x,y,z,t[N],f[N],s[N],ans;
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d%d%d",&x,&y,&z);
        t[x]=y;f[y]=x;s[x]=z;
    }
    rep(i,1,n)if(!f[i]&&t[i])ans++;
    printf("%d\n",ans);
    rep(i,1,n)if(!f[i]&&t[i]){ans=1000000;int j;
        for(j=i;t[j];j=t[j]){
            if(ans>s[j])ans=s[j];
        }
        printf("%d %d %d\n",i,j,ans);
    }
}