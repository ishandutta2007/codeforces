
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
vector<int> v[100005];
vector<int> stk;
bool cmp(const int &x,const int &y){
    return v[x].size()<v[y].size();
}
void dfs(int x){
    sort(v[x].begin(),v[x].end(),cmp);
    stk.pb(x);
    for(auto it:v[x]){
        dfs(it);
    }
}
void solve(int T){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<=n+1;i++)v[i].clear();
    stk.clear();
    int b[100005];
    int k=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&b[i]);
        v[b[i]].pb(i);
        if(b[i]>i){
            k=i;
        }
    }
    vector<int> ans;
    if(v[n+1].size()){
        dfs(n+1);
    }
    else if(v[0].size()){
        dfs(0);
    }
    printf("%d\n",k);
    reverse(stk.begin(),stk.end());stk.pop_back();
     reverse(stk.begin(),stk.end());
    for(auto it:stk)printf("%d ",it);
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/