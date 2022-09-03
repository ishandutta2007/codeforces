#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
int f[2005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n;
    scanf("%d",&n);
    pii p[2005];
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    LL c[2005],k[2005];
    for(int i = 1;i<=n;i++)scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&k[i]);
    vector<pair<LL,pii> > v;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            v.pb(mp((k[i]+k[j])*(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)),mp(i,j)));
        }
        v.pb(mp(c[i],mp(0,i)));
        f[i]=i;
    }
    LL ans=0;
    vector<int> res;
    vector<pii> edge;
    sort(v.begin(),v.end());
    for(auto it:v){
        int a=it.y.x;
        int b=it.y.y;
        int fa=Find(a),fb=Find(b);
        if(fa!=fb){
            ans+=it.x;
            f[fa]=fb;
            if(a==0)res.pb(b);
            else edge.pb(mp(a,b));
        }
    }
    printf("%lld\n",ans);
    printf("%d\n",res.size());
    for(auto it:res)printf("%d ",it);
    printf("\n");
    printf("%d\n",edge.size());
    for(auto it:edge){
        printf("%d %d\n",it.x,it.y);
    }
}