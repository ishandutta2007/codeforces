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
#define index Index
LL cal(LL w,LL r,LL b){
    LL ans=1e18;
    for(int i = 0;i<=b;i++){
        ans=min(ans,(w+b-i)*(r-i));
    }
    return ans;
}
vector<int> ans;
vector<int> v[200005];
int dfs(int x,int f){
    vector<int> tmp;
    //tmp.pb(0);
    for(auto it:v[x]){
        if(it!=f){
            tmp.pb(dfs(it,x));
        }
    }
    sort(tmp.begin(),tmp.end());
    for(int i = 0;i+1<tmp.size();i++){
        ans.pb(tmp[i]);
    }
    if(tmp.empty())return 1;
    else return tmp.back()+1;
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    ans.pb(dfs(1,0));
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    if(ans.size()<=k){
        LL res=0;
        for(int i = ans.size();i<=k;i++){
            res=max(res,i*1ll*(n-i));
        }
        printf("%lld\n",res);
    }
    else{
        LL sum=0;
        for(int i = k;i<ans.size();i++)sum+=ans[i];
        printf("%lld\n",cal(n-k-sum,k,sum));
    }
}
int main(){
    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/