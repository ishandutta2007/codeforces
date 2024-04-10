#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(int i=first[x];i;i=nxt[i])
#define uu unsigned
#define fi first
#define se second
#define od(x) ((x)&1)
#define ev(x) (od(x)^1)
#define mi2(x) (1<<(x))
#define scanf a1234=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
char buf[1<<18],*bufs=buf,*buft=buf;
inline int gc(){
    return bufs==buft&&(buft=(bufs=buf)+fread(buf,1,1<<18,stdin)),bufs==buft?-1:*bufs++;
}
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int n,m,k;char mp[2003][2003];
int up[2003][2003],dw[2003][2003];
pii gi[2003];
int dp[2003][2003];
int ans[2003];
int q1[2003],q2[2003],h1,t1,h2,t2;
inline bool can(int len,int x){
    h1=1,t1=0,h2=1,t2=0;int p=0;
    for(int y=1;y<=m;++y){
        if(mp[x][y]!='.')h1=h2=1,t1=t2=0,p=y;
        else{
            if(h1<=t1&&q1[h1]==y-len)++h1;
            if(h2<=t2&&q2[h2]==y-len)++h2;
            while(h1<=t1&&up[x][y]<=up[x][q1[t1]])--t1; q1[++t1]=y;
            while(h2<=t2&&dw[x][y]<=dw[x][q2[t2]])--t2; q2[++t2]=y;
            if(y-p>=len&&up[x][q1[h1]]+dw[x][q2[h2]]+1>=len)return 1;//printf("%d %d %d %d %d\n",len,x,y,q1[h1],q2[h2]),1;
        }
    }
    return 0;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);
    for(int i=1;i<=k;++i)scanf("%d%d",&gi[i].fi,&gi[i].se),mp[gi[i].fi][gi[i].se]='#';
    for(int j=1;j<=m;++j){
        int now=0;
        for(int i=1;i<=n;++i){
            up[i][j]=i-now-1;
            if(mp[i][j]!='.')now=i;
        }
        now=n+1;
        for(int i=n;i;--i){
            dw[i][j]=now-i-1;
            if(mp[i][j]!='.')now=i;
        }
    }
    //for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)printf("%d %d %d %d\n",i,j,up[i][j],dw[i][j]);
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(mp[i][j]=='.')dp[i][j]=min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1,ans[k]=max(ans[k],dp[i][j]);
    for(int ii=k,x,y;ii;--ii){
        x=gi[ii].fi,y=gi[ii].se;
        mp[x][y]='.';
        for(int i=x-1;i;--i){
            dw[i][y]+=dw[x][y]+1; if(mp[i][y]!='.')break;
        }
        for(int i=x+1;i<=n;++i){
            up[i][y]+=up[x][y]+1; if(mp[i][y]!='.')break;
        }
        int l=1,r=m,mid;
        while(l<r){
            mid=(l+r+1)>>1;
            if(can(mid,x))l=mid;
            else r=mid-1;
        }
        ans[ii-1]=max(ans[ii],l);
        //puts("------------_");
//        printf("%d %d\n",ans[k],ans[k-1]);
    }
    for(int i=1;i<=k;++i)printf("%d\n",ans[i]);
    return 0;
}