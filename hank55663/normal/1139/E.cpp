#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
#define MXN 3000
int vis[5005];
int match[5005];
int match2[5005];
set<int> v[5005];
bool dfs(int x){
    //printf("in:x %d\n",x);
    if(vis[x])return false;
    vis[x]=1;
    for(auto it:v[x]){
        if(match[it]==-1||dfs(match[it])){
           // printf("%d\n",it);
            match[it]=x;
            match2[x]=it;
            return true;
        }
    }
 //   printf("x:%d\n",x);
    return false;
}
int max_match(int x){
    MEMS(match);
    for(int i = 0;i<=x;i++){
        MEM(vis);
        //printf("i:%d\n",i);
        if(!dfs(i)){
            return i;
        }
    }
}
int cnt[5005][5005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int p[5005];
    for(int i = 1;i<=n;i++)
    scanf("%d",&p[i]);
    int club[5005];
    for(int i =1;i<=n;i++){
        scanf("%d",&club[i]);
        cnt[club[i]][p[i]]++;
        if(cnt[club[i]][p[i]]==1)
        v[p[i]].insert(club[i]);
    }
    int q;
    scanf("%d",&q);
    int Max=max_match(m)-1;
    while(q--){
        int x;
        scanf("%d",&x);
        cnt[club[x]][p[x]]--;
        if(cnt[club[x]][p[x]]==0){
          //  printf("%d %d %d\n",club[x],p[x],match[club[x]]);
            v[p[x]].erase(club[x]);
            if(match[club[x]]==p[x]){
                match[club[x]]=-1;
                MEM(vis);
               // printf("? %d %d\n",p[x],Max);
                while(p[x]<=Max&&!dfs(p[x])){
                    match[match2[Max]]=-1;
                    Max--;
                    MEM(vis);
                }
            }
           // printf("%d %d\n",match2[1],match[match2[1]]);
        }
        printf("%d\n",Max+1);
    }
}