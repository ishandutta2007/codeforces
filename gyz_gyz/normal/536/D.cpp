#include<cstdio>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 2001
#define ll long long
#define inf 1000000000000000000ll
using namespace std;
vector<ll>e[mx];vector<ll>w[mx];
ll a[mx],b[mx],pt[mx][mx],ps[mx][mx],p1[mx][mx],p2[mx][mx],v1[mx][mx],v2[mx][mx],v[mx],s1[mx],s2[mx];
ll n,m,S,T,w1,w2,x,y,z,g;
struct pr{ll x,y;}r[mx];
inline bool cmp(pr x,pr y){return x.x<y.x;}
int main(){
    scanf("%I64d%I64d",&n,&m);
    scanf("%I64d%I64d",&S,&T);
    rep(i,1,n)scanf("%I64d",&a[i]);
    rep(i,1,m){
        scanf("%I64d%I64d%I64d",&x,&y,&z);
        e[x].push_back(y);w[x].push_back(z);
        e[y].push_back(x);w[y].push_back(z);
    }
    rep(i,1,n)b[i]=inf,v[i]=0;b[S]=0;
    rep(i,1,n){
        x=0;g=inf;
        rep(j,1,n)if(!v[j]&&b[j]<g)g=b[j],x=j;
        if(!x)break;v[x]=1;int sz=e[x].size()-1;
        rep(j,0,sz){int tt=e[x][j];
            if(!v[tt]&&b[x]+w[x][j]<b[tt])b[tt]=b[x]+w[x][j];
        }
    }
    rep(i,1,n)r[i].x=b[i],r[i].y=i;
    sort(r+1,r+n+1,cmp);r[0].x=-1;
    rep(i,1,n)if(r[i].x==r[i-1].x)s1[r[i].y]=w1;else s1[r[i].y]=++w1;
    rep(i,1,n)b[i]=inf,v[i]=0;b[T]=0;
    rep(i,1,n){
        x=0;g=inf;
        rep(j,1,n)if(!v[j]&&b[j]<g)g=b[j],x=j;
        if(!x)break;v[x]=1;int sz=e[x].size()-1;
        rep(j,0,sz){int tt=e[x][j];
            if(!v[tt]&&b[x]+w[x][j]<b[tt])b[tt]=b[x]+w[x][j];
        }
    }
    rep(i,1,n)r[i].x=b[i],r[i].y=i;
    sort(r+1,r+n+1,cmp);r[0].x=-1;
    rep(i,1,n)if(r[i].x==r[i-1].x)s2[r[i].y]=w2;else s2[r[i].y]=++w2;
    rep(i,1,n)pt[s1[i]][s2[i]]+=a[i],ps[s1[i]][s2[i]]+=a[i];
    rep(i,1,n)v1[s1[i]][s2[i]]+=1,v2[s1[i]][s2[i]]+=1;    
    rep(i,1,w1)rep(j,2,w2)pt[i][j]+=pt[i][j-1],v1[i][j]+=v1[i][j-1];
    rep(i,2,w1)rep(j,1,w2)ps[i][j]+=ps[i-1][j],v2[i][j]+=v2[i-1][j];
    dep(i,w1-1,0)dep(j,w2-1,0){ll s1,s2;
        s1=p1[i+1][j]+pt[i+1][w2]-pt[i+1][j];
        s2=-p2[i+1][j]+pt[i+1][w2]-pt[i+1][j];
        if(v1[i+1][w2]-v1[i+1][j]==0)s2=-inf;
        if(s1>s2)p1[i][j]=s1;else p1[i][j]=s2;
        s1=-p1[i][j+1]+ps[w1][j+1]-ps[i][j+1];
        s2=p2[i][j+1]+ps[w1][j+1]-ps[i][j+1];
        if(v2[w1][j+1]-v2[i][j+1]==0)s1=-inf;
        if(s1>s2)p2[i][j]=s1;else p2[i][j]=s2;
    }
    if(p1[0][0]<0)printf("Cry\n");
    if(p1[0][0]>0)printf("Break a heart\n");
    if(p1[0][0]==0)printf("Flowers\n");
}