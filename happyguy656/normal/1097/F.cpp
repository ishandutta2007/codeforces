#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3,mxm=7003;
int n,q,mu[mxm],v[mxm],pr[mxm],pt;
bitset<mxm>u[mxm],f[mxn];

int main(){
    mu[1]=1;
    for(int i=2;i<mxm;++i){
        if(!v[i])v[i]=i,pr[++pt]=i,mu[i]=-1;
        
        for(int j=1;j<=pt&&pr[j]<=v[i]&&i*pr[j]<mxm;++j){
            v[i*pr[j]]=pr[j];
            if(pr[j]!=v[i])mu[i*pr[j]]=-mu[i];
        }
    }
    for(int i=1;i<mxm;++i)for(int j=i;j<mxm;j+=i)u[i][j]=mu[j/i];
    scanf("%d%d",&n,&q);while(q--){
        int o,x,y,z;scanf("%d",&o);
        if(o==1){
            scanf("%d%d",&x,&y);
            f[x].reset();
            for(int i=1;i*i<=y;++i)if(y%i==0)f[x][i]=f[x][y/i]=1;
        }else if(o==2){
            scanf("%d%d%d",&x,&y,&z);
            f[x]=f[y]^f[z];
        }else if(o==3){
            scanf("%d%d%d",&x,&y,&z);
            f[x]=f[y]&f[z];
        }else if(o==4){
            scanf("%d%d",&x,&y);
            printf("%d",(f[x]&u[y]).count()%2);
        }
    }
    puts("");
    return 0;
}