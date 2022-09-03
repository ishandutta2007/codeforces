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
vector<int> v[300005];
int dfs(int x,int f){
    vector<int> vv;
    for(auto it:v[x]){
        if(it!=f){
            vv.pb(dfs(it,x));
        }
    }  
    if(vv.size()==2)return min(vv[0],vv[1])+2;
    if(vv.size()==1) return 2;
    return 1;
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        v[i].clear();
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    printf("%d\n",n-dfs(1,0));
}

int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}