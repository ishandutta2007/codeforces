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
vector<int> v[200005];
int val[200005];
int Size[200005];
vector<int> ans;
void dfs(int x,int f,int sum){
    Size[x]=1;
    val[x]=sum;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x,sum+1);
            Size[x]+=Size[it];
        }
    }
    val[x]-=Size[x];
    ans.pb(val[x]);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0,1);
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    LL res=0;
    for(int i = 0;i<k;i++)res+=ans[i];
    printf("%lld\n",res);
}
/*
00 00
01 10
10 11
11 01

*/