#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
vector<pll> v[200005];
int Size[200005];
priority_queue<pair<LL,pii> > pq;
LL sum=0;
void dfs(int x,int f){
    if(v[x].size()==1&&x!=1)
    Size[x]=1;
    else Size[x]=0;

    for(auto it:v[x]){
        if(it.x!=f){
            dfs(it.x,x);
            pq.push(mp((it.y+1)/2ll*Size[it.x],mp(Size[it.x],it.y)));
            Size[x]+=Size[it.x];
            sum+=it.y*1ll*Size[it.x];
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        sum=0;
        while(pq.size())pq.pop();
        LL n,s;
        scanf("%lld %lld",&n,&s);
        for(int i= 1;i<=n;i++){
            v[i].clear();
        }
        for(int i = 1;i<n;i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            v[x].pb(mp(y,w));
            v[y].pb(mp(x,w));
        }
        dfs(1,0);
        int ans=0;
        while(sum>s){
            auto p=pq.top();
            pq.pop();
            ans++;
            sum-=p.x;
            p.y.y/=2;
          //  printf("%lld %d %d %d\n",sum,p.y.x,p.y.y,p.x);
            pq.push(mp((p.y.y+1)/2ll*p.y.x,p.y));
        }
        printf("%d\n",ans);
    }
}