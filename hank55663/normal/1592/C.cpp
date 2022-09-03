#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
int a[100005];
vector<int> v[100005];
int sum=0;
int odd=0,even=0;
int tot[100005];
bool dfs(int x,int f){
    tot[x]=a[x];
    int ok=0;
    int cnt=0;
    for(auto it:v[x]){
        if(it!=f){
            if(dfs(it,x)){
            ok|=1;
            cnt++;
            }
            tot[x]^=tot[it];
        }
    }
    if(f!=0){
    if(tot[x]==0&&sum==0)even=1;
    if(ok&&tot[x]==0)odd=1;
    if(tot[x]==sum)ok=1;
    }
    if(cnt>=2)odd=1;
    return ok;
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    sum=odd=even=0;

    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        sum^=a[i];
    }
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    if(sum==0){
        printf("Yes\n");
    }
    else if(sum!=0&&odd&&k>=3){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
7
34 38 10
8 32 9
3 7 10
5 13 9
23 40 5
28 34 1
24 26 10
*/