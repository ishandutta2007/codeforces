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
#define MXN 3000000
vector<int> v[1005];
int a[1005],b[1005];
LL d[1005];
int from[1005];
int f[1005];
int vis[1005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 2;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 2;i<=n;i++){
        scanf("%d",&b[i]);
    }
    vector<pii> edge;
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        edge.pb(mp(x,y));
        v[x].pb(y);
        v[y].pb(x);
    }
    int Max=1e9+1,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
       // printf("!!!%d\n",mid);
        for(int i = 1;i<=n;i++)f[i]=i,d[i]=-1;
        while(true){
            LL now=mid;
            for(int i = 1;i<=n;i++){
                d[i]=-1,vis[i]=0;
                if(f[i]==1)now+=b[i];
            }
            queue<int> q;
            q.push(1);
            d[1]=now;
            vis[1]=1;
            int ok=0;
            vector<int> tmp;
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(auto it:v[x]){
                    if(!vis[it]){
                        if(f[it]==1){
                            q.push(it);
                            vis[it]=1;
                            d[it]=d[1];
                        }
                        else{
                            if(d[x]>a[it]){
                                q.push(it);
                                vis[it]=1;
                                d[it]=d[x]+b[it];
                                from[it]=x;
                            }
                        }
                    }
                    else{
                        if(f[it]==1){
                            if(from[x]!=it&&f[x]!=1){
                                ok=1;
                                int a=x,b=it;
                                while(f[a]!=1)tmp.pb(a),a=from[a];
                                while(f[b]!=1)tmp.pb(b),b=from[b];//printf("%d\n",b);
                                break;
                            }
                        }
                        else if(from[x]!=it){
                            ok=1;
                            int a=x,b=it;
                            while(f[a]!=1)tmp.pb(a),a=from[a];
                            while(f[b]!=1)tmp.pb(b),b=from[b];
                            break;
                        }
                    }
                }
                if(ok)break;
            }
            if(ok){
                for(auto it:tmp){
                    f[it]=1;
                    //printf("%d ",it);
                }
                //printf("\n");
            }
            else{
                break;
            }
        }
        int ok=1;
        for(int i = 1;i<=n;i++){
            if(f[i]!=1)ok=0;
        }
        if(ok)Max=mid;
        else Min=mid;
       // break;
    }
    printf("%d\n",Max);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
100
5 6
9 10 7 5
4 4 4 9
1 2
4 5
3 5
2 3
1 4
1 5

*/