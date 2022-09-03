#include<bits/stdc++.h>
using namespace std;
#pragma optimizer(-Ofast)
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
#define pdd pair<double,double>
#define cpdd const pdd
#define rank Rank
#define MXN 15000
LL ans[200005];
int f[200005];
LL Size[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)
        f[i]=i,Size[i]=1;
    vector<pair<int,pii> > v;
    for(int i = 0;i<n-1;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v.pb(mp(c,mp(a,b)));
    }
    sort(v.begin(),v.end());
    LL now=0;
    for(auto it:v){
        int fx=Find(it.y.x);
        int fy=Find(it.y.y);
        now-=Size[fx]*(Size[fx]-1)/2;
        now-=Size[fy]*(Size[fy]-1)/2;
        Size[fx]+=Size[fy];
        f[fy]=fx;
        now+=Size[fx]*(Size[fx]-1)/2;
        ans[it.x]=now;
    }
    LL last=0;
    for(int i = 1;i<=200000;i++){
        if(ans[i]==0){
            ans[i]=last;
        }
        else{
            last=ans[i];
        }
    }
    while(m--){
        int x;
        scanf("%d",&x);
        printf("%lld ",ans[x]);
    }
    printf("\n");
    return 0;
}