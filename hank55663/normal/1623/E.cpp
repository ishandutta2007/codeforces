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
const int mod=1e9+7;
int l[200005],r[200005];
int p[200005];
char c[200005];
vector<int> v;
void dfs(int x){
    if(!x)return;
    dfs(l[x]);
    v.pb(x);
    dfs(r[x]);
}
vector<int> ans;
int k;
int ok[200005];
vector<int> stk;
bool dfs2(int x,int ook){
    if(!x)return false;
    stk.pb(x);
    int res=dfs2(l[x],ook);
    ans.pb(x);
    if(res){
        ans.pb(x);
        dfs2(r[x],true);
        return true;
    }
    if(ook&&ok[x]&&k>=stk.size()){
        k-=stk.size();
        stk.clear();
        ans.pb(x);
        dfs2(r[x],true);
        return true;
    }
    else{
        dfs2(r[x],false);
        stk.pop_back();
        return false;
    }
}
void solve(){
    int n;
    scanf("%d %d",&n,&k);
    scanf("%s",c+1);
    for(int i = 1;i<=n;i++){
        scanf("%d %d",&l[i],&r[i]);
    }
    dfs(1);
    if(n==1){
        printf("%s\n",c+1);
        return;
    }
    else{
        for(int i = v.size()-2;i>=0;i--){
            if(c[v[i]]<c[v[i+1]])ok[v[i]]=1;
            else if(c[v[i]]==c[v[i+1]])ok[v[i]]=ok[v[i+1]];
        }
       // for(int i = 1;i<=n;i++)printf("%d ",ok[i]);
    }
    dfs2(1,true);
    for(auto it:ans)printf("%c",c[it]);
    printf("\n");
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
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