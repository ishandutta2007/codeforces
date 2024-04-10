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
using namespace std;
#define MXN 100005
int ans;
vector<int> v[200005];
int ok[200005];
int dfs(int x,int f){
    ok[x]=0;
    vector<int> dep;
    for(auto it:v[x]){
        if(it!=f){
            dep.pb(dfs(it,x));
            ok[x]+=ok[it];
            /*if(dep.back()+1>ans){
                if(ok[it]==0)ok[x]++;
               // ok[x]+=ok[it];
            }*/
        }
    }
    if(dep.empty())
    dep.pb(0);
    sort(dep.begin(),dep.end());
    
   // if(dep.size())
   // for(auto it:dep){
    //    printf("%d ",it);
    //}
   // printf("x:%d\n",x);
    if(x!=1){
        if(dep.back()+1>ans){
            if(ok[x]==0)
            ok[x]=1;
        }
    }
    else{
        if(dep[dep.size()-1]>ans)ok[x]=1;
        if(dep.size()>=2)
        if(dep[dep.size()-2]+1>ans)ok[x]=1;
    }
    return dep[0]+1;
}
void solve(){
    ans=1;
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    int Max=n,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        ans=mid;
        dfs(1,0);
        if(ok[1])Min=mid;
        else Max=mid;
    }
    printf("%d\n",Max);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
       solve();
    }
}
/*
*/