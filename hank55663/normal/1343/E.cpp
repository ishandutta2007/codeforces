#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
vector<int> v[200005];
int dis[3][200005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,a[3];
        scanf("%d %d %d %d %d",&n,&m,&a[0],&a[1],&a[2]);
        for(int i = 1;i<=n;i++)v[i].clear();
        LL p[200005];
        //vector<int> p;
        for(int i = 1;i<=m;i++){
            //int x;
            scanf("%lld",&p[i]);
            //p.pb(x);
        }
        p[0]=0;
        sort(p+1,p+m+1);
        for(int i = 1;i<=m;i++){
            p[i]+=p[i-1];
        }
        for(int i = 1;i<=m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        for(int i = 0;i<3;i++){
            queue<int> q;
            q.push(a[i]);
            
            fill(dis[i],dis[i]+n+1,1e9);
            dis[i][a[i]]=0;
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(auto it:v[x]){
                    if(dis[i][it]>dis[i][x]+1){
                        dis[i][it]=dis[i][x]+1;
                        q.push(it);
                    }
                }
            }
        }
        LL ans=1e18;
        for(int i = 1;i<=n;i++){
            if(dis[0][i]+dis[1][i]+dis[2][i]<=m)
            ans=min(ans,p[dis[0][i]+dis[1][i]+dis[2][i]]+p[dis[1][i]]);//+p[dis[2][i]]);
        }
        printf("%lld\n",ans);
    }
}