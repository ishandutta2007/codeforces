#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int go[1000005];
int instk[1000005];
vector<int> stk;
void dfs(int x){
    if(instk[x]){
        vector<int> res;
        while(stk.back()!=x){
            res.pb(stk.back());
            stk.pop_back();
        }
        res.pb(x);
        printf("%d\n",res.size());
        for(auto it:res){
            printf("%d ",it);
        }
        printf("\n");
        return;
    }
    stk.pb(x);
    instk[x]=1;
    dfs(go[x]);
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        go[i]=i-x;
    }
    dfs(1);
    for(int i = 1;i<=n;i++)
        go[i]=0,instk[i]=0;
    stk.clear();
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
1-n 0
2-n 1
3-n 2
-3 0
-2 1
-1 2
0 3
*/
/*
1 0
2 -10  01
3 -20 -1 1 0 2


*/
/*

k*cnt[i]-k*cnt[j]=i-j;
k*cnt[i]-i=k*cnt[j]-j
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5    3
1 2 3 5 6    4 
1 2 3 4 6
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/