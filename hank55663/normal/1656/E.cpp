#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
vector<int> v[100005];
int val[100005];
void dfs(int x,int f,int d){
    if(d==1){
        val[x]=1-(v[x].size()-1)*(-1);
    }
    else{
        val[x]=-1-(v[x].size()-1)*1;
    }
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x,d^1);
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0,0);
    for(int i =1;i<=n;i++){
        printf("%d ",val[i]);
    }
    printf("\n");
}


int main(){
    int t=10000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/