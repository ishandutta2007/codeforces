#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acosl(-1)
//#define N 524288
#define ld long double
using namespace std;
vector<int> v[100005];
int odd=0,even=0;
void dfs(int x,int f,int sum){
    if(v[x].size()==1){
        if(sum&1)odd++;
        else even++;
    }
    for(auto it:v[x]){
        if(it!=f)
        dfs(it,x,sum+1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0,0);
    if(odd&& even){
        printf("3 ");
    }
    else{
        printf("1 ");
    }
    int ans2=n-1;
    for(int i = 1;i<=n;i++){
        int cnt=0;
        for(auto it:v[i]){
            if(v[it].size()==1)cnt++;
        }
        if(cnt>=2)ans2-=cnt-1;
    }
    printf("%d",ans2);
}