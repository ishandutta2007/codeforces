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
#define index Index
#define MXN 1000000
vector<int> v[200005];
int degree[200005];
int vis[200005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        v[i].clear();
        degree[i]=0;
        vis[i]=0;
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        degree[x]++;
        degree[y]++;
    }
    if(n==1)printf("0\n");
    else{
        int ok=1;
        queue<int> q;
        int ans=0;
        for(int i = 1;i<=n;i++){
            if(v[i].size()>2){
                ok=0;
            }
            if(degree[i]==1)q.push(i),vis[i]=1,ans++;
        }
        if(ok){
            printf("1\n");
        }
        else{
            while(!q.empty()){
                int x=q.front();
              //  printf("%d\n",x);
                q.pop();
                for(auto it:v[x]){
                    if(!vis[it]&&--degree[it]==1&&v[it].size()==2){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            for(int i = 1;i<=n;i++){
                if(!vis[i]){
                    int ok=0;
                    for(auto it:v[i]){
                        if(vis[it]){
                            ok=1;
                        }
                    }
                    if(ok)ans--;
                }
            }
            printf("%d\n",ans);
        }
    }
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}