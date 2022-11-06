#include<cstdio>
#include<algorithm>
#include<vector>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
struct dv{long double a;int b;}r[100001],s[100001],h;
vector<dv>p[100001];
double a[100001];
double z;
int wr[100001],t[100001],k,n,m,w,x,y;
inline bool cmp(const dv &a,const dv &b){return a.a>b.a;}
int main(){
    scanf("%d%d%d",&k,&n,&m);
    rep(i,1,k)scanf("%lf",&a[i]);
    rep(i,1,n){
        scanf("%d%d%lf",&x,&y,&z);
        h.a=z;h.b=i;t[i]=x;
        if(x==1)if(h.a>r[y].a)r[y]=h;
        if(x==2)p[y].push_back(h);
        if(x==3)s[++w]=h;
    }
    rep(i,1,k)if(r[i].a>a[i]){
        h.a=r[i].a-a[i];h.b=r[i].b;
        p[i].push_back(h);
    }
    rep(i,1,k)sort(p[i].begin(),p[i].end(),cmp);
    rep(i,1,k){
        int g=p[i].size();
        if(g){h.a=(p[i][0].a+a[i])/a[i];h.b=p[i][0].b;s[++w]=h;}
        rep(j,1,g-1){
            h.a=(p[i][j].a+a[i]+p[i][j-1].a)/(a[i]+p[i][j-1].a);h.b=p[i][j].b;
            s[++w]=h;p[i][j].a+=p[i][j-1].a;
        }
    }
    sort(s+1,s+w+1,cmp);
    for(;(m)&&(!s[m].b);)m--;
    rep(i,1,m)wr[i]=s[i].b;printf("%d\n",m);
    rep(i,1,m)if(t[wr[i]]==1)printf("%d ",wr[i]);
    rep(i,1,m)if(t[wr[i]]==2)printf("%d ",wr[i]);
    rep(i,1,m)if(t[wr[i]]==3)printf("%d ",wr[i]);
}