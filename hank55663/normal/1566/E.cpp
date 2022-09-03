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
int mod=1e9+7;
vector<int> v[200005];
vector<int> arr;
int dfs(int x,int f){
    int tot=0;
    for(auto it:v[x]){
        if(it!=f){
            tot+=dfs(it,x);
        }
    }
    if(tot){
        arr.pb(tot);
        return 0;
    }
    else {
        return 1;
    }
}
void solve(int T){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    arr.clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    for(int  i=0;i+1<arr.size();i++)arr[i]--;
    int ans=0;
    for(int i = 0;i<arr.size();i++)ans+=arr[i];//printf("%d ",arr[i]);
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve(i);
    }
    return 0;
}
/*
000010000
001010000
001010100
001011100

1 1 2
1 1 2 1
2 1
2


XOXOXOXOOXOXXOXOXOXOOXOX
*/