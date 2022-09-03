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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int f[100005];
int f2[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int Find2(int x){
    if(f2[x]==x)return x;
    return f2[x]=Find2(f2[x]);
}
vector<int> v[100005];
vector<int> tmp;
int vis[100005];
void dfs(int x,int f){
    tmp.pb(x);
    vis[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }

}
void solve(){
    int n=10,m1=rand()%n,m2=rand()%n;
    scanf("%d %d %d",&n,&m1,&m2);
  //  printf("%d %d %d\n",n,m1,m2);
    for(int i = 1;i<=n;i++)f[i]=f2[i]=i,v[i].clear(),vis[i]=0;
    tmp.clear();
    for(int i = 0;i<m1;i++){
        int x=rand()%n+1,y=rand()%n+1;
        scanf("%d %d",&x,&y);
        while(Find(x)==Find(y)){
             x=rand()%n+1,y=rand()%n+1;
        }
       // printf("%d %d\n",x,y);
        int a=Find(x),b=Find(y);
        f[a]=b;
    }
    for(int i = 0;i<m2;i++){
        int x=rand()%n+1,y=rand()%n+1;
        scanf("%d %d",&x,&y);
        while(Find2(x)==Find2(y)){
            x=rand()%n+1,y=rand()%n+1;
        }
       // printf("%d %d\n",x,y);
        v[x].pb(y);
        v[y].pb(x);
        f2[Find2(x)]=Find2(y);
    }
    priority_queue<pair<int,vector<int> > ,vector<pair<int,vector<int> > > ,greater<pair<int,vector<int> > > > pq;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
            pq.push(mp(tmp.size(),tmp));
            tmp.clear();
        }
    }
    vector<pii> ans;
    for(int i = 1;i<=n;i++){
        for(int j  =i+1;j<=n;j++){
            //int a=Find(i),b=Find(j);
            if(Find(i)!=Find(j)&&Find2(i)!=Find2(j)){
                ans.pb(mp(i,j));
                f[Find(i)]=Find(j);
                f2[Find2(i)]=Find2(j);
            }
        }
    }
  /*  while(pq.size()!=1){
        auto p=pq.top().y;
        pq.pop();
        auto q=pq.top().y;
        pq.pop();
        int a=Find(p[0]),aa=p[0];
        int b=-1,bb=-1;
        for(auto it:p){
            if(Find(it)!=a){
                b=Find(it);
                bb=it;
                break;
            }
        }
        for(auto it:q){
            if(Find(it)!=a){
                ans.pb(mp(it,aa));
                 printf("add %d %d\n",it,aa);
                assert(Find(it)!=Find(aa));
                assert(Find2(it)!=Find2(aa));
               
                f[Find(it)]=a;
                f2[Find2(it)]=Find2(aa);
                break;
            }
            if(b!=-1&&Find(it)!=b){
                ans.pb(mp(it,bb));
                  printf("add %d %d\n",it,bb);
                 // assert(Find(it)==b);
                assert(Find(it)!=Find(bb));
                assert(Find2(it)!=Find2(bb));
               // prin
                f[Find(it)]=b;
                f2[Find2(it)]=Find2(bb);
                break;
            }
        }
        for(auto it:q)p.pb(it);
        pq.push(mp(p.size(),p));
    }*/
    printf("%d\n",ans.size());
    for(auto it:ans)printf("%d %d\n",it.x,it.y);
}
int main(){
    int t=1;0000;//00;//00;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/