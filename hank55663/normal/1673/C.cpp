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
int dp[40005];
const int mod=1e9+7;
vector<int> v;
void dfs(int x,vector<int> &stk){
    if(x){
        reverse(stk.begin(),stk.end());
        LL tmp=x;
        for(auto it:stk)tmp=tmp*10+it;
        v.pb(tmp);
         reverse(stk.begin(),stk.end());
         int a=stk.back();
         stk.pop_back();
          reverse(stk.begin(),stk.end());
        tmp=x;
        for(auto it:stk)tmp=tmp*10+it;
        v.pb(tmp);
         reverse(stk.begin(),stk.end());
         stk.pb(a);
    }
    if(x>100)return;
    for(int j = 0;j<=9;j++){
        if(x==0&&j==0)continue;
        stk.pb(j);
        dfs(x*10+j,stk);
        stk.pop_back();
    }
}
void solve(){

    vector<int> tmp;
    dfs(0,tmp);
    sort(v.begin(),v.end());
    /*for(auto it:v)printf("%d ",it);
    printf("\n");*/
    dp[0]=1;
    for(auto it:v){
        for(int j = it;j<=40000;j++){
            dp[j]+=dp[j-it];
            dp[j]%=mod;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",dp[x]);
    }
}
int main(){
    srand(time(NULL));
    int t=1;0000;
    //scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/