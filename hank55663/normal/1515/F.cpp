#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
queue<pii> v[300005];
LL a[300005];
int f[300005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);
    priority_queue<pll> pq;
    LL sum=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        pq.push(mp(a[i],i));
        sum+=a[i];
        f[i]=i;
    }
    if(sum<(n-1)*1ll*t){
        printf("NO\n");
        return;
    }
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int a=Find(x),b=Find(y);
        if(a!=b){
        //    printf("%d\n",i);
            f[a]=b;
            v[x].push(mp(y,i));
            v[y].push(mp(x,i));
        }
    }
    for(int i = 1;i<=n;i++){
        f[i]=i;

    }
    printf("YES\n");
    int tot=0;
    while(!pq.empty()){
        if(tot==n-1)break;
        pll p=pq.top();
        pq.pop();
        p.y=Find(p.y);
        if(a[p.y]!=p.x)continue;
        //printf("%d\n",p.y);
        assert(v[p.y].size());
        
        while(Find(v[p.y].front().x)==Find(p.y))v[p.y].pop(),assert(v[p.y].size());
        pll pp=v[p.y].front();
        v[p.y].pop();
        printf("%d\n",pp.y);
        tot++;
        int x=p.y,y=Find(pp.x);
        if(v[x].size()<v[y].size()){
            swap(x,y);
        }
        f[y]=x;
        a[x]+=a[y];
        a[x]-=t;
        pq.push(mp(a[x],x));
        while(v[y].size()){
            v[x].push(v[y].front());
            v[y].pop();
        }
    
    }
    
}
int main(){
  //  for(int i = 1;i*i<=1e9;i++)s.insert(i*i);
    int t=1;00000;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36
6x+s=ty
x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/