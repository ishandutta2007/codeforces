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
int color[200005];
vector<int> v[200005];
bool dfs(int x,int c){
   // printf("%d %d\n",x,c);
    color[x]=c;
    for(auto it:v[x]){
        if(color[it]==-1){
            if(!dfs(it,c^1))return false;
        }
        else{
            if(color[it]==c)return false;
        }
    }
    return true;
}
int val[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&val[i]);
        val[i]=-val[i];
        v[i].clear();
        color[i]=-1;
    }
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        val[i]+=x;
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    LL sum=0;
    for(int i = 1;i<=n;i++){
        sum+=val[i];
      //  printf("%d ",val[i]);
    }
    if(sum%2){
        printf("NO\n");
    }
    else if(dfs(1,0)){
        LL ans[2]={0,0};
        for(int i = 1;i<=n;i++){
            ans[color[i]]+=val[i];
          //  printf("%d ",color[i]);
        }

        if(ans[0]==ans[1])printf("YES\n");
        else printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}
int main(){
    int t=1;//00;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/