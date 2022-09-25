#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;

int n;
vector<int> al[3005];
vector<ii> edges;

long long sz[3005];
int pre[3005];
int post[3005];
int parent[3005];

int counter=0;
void dfs_sz(int i,int p){
    pre[i]=counter++;
    sz[i]=1;
    for (auto &it:al[i]){
        if (it==p) continue;
        parent[it]=i;
        dfs_sz(it,i);
        sz[i]+=sz[it];
    }
    post[i]=counter++;
}

long long memo[3005][3005];

long long dp(int i,int j){
    if (pre[i]>pre[j]) swap(i,j);
    if (memo[i][j]!=-1) return memo[i][j];

    long long res;
    long long __max=0;
    int p1,p2;

    if (post[i]<post[j]){///different subtree
        res=sz[i]*sz[j];
        p1=parent[i];
        p2=parent[j];
    }
    else{
        for (auto &it:al[i]){
            if (it==parent[i]) continue;
            if (pre[it]<=pre[j] && post[j]<=post[it]){
                p1=it;
                break;
            }
        }
        p2=parent[j];
        res=(n-sz[p1])*sz[j];
    }

    for (auto &it:al[i]){
        if (it==p1) continue;
        __max=max(__max,dp(it,j));
    }

    for (auto &it:al[j]){
        if (it==p2) continue;
        __max=max(__max,dp(i,it));
    }

    return memo[i][j]=res+__max;
}
int main(){
    //freopen("input.txt","r",stdin);

    memset(memo,-1,sizeof(memo));
    scanf("%d",&n);
    int a,b;

    for (int x=1;x<n;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
        edges.push_back(ii(a,b));
    }

    parent[1]=-1;
    dfs_sz(1,-1);

    long long ans=0;

    for (auto &it:edges){
        ans=max(ans,dp(it.first,it.second));
    }

    printf("%lld\n",ans);
}