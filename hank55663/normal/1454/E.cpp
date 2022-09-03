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
#define next Next
using namespace std;
vector<int> v[200005];
int circle[200005];
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
vector<int> stk;
bool dfs(int s,int t,int f){
    //printf("%d\n",s);
    stk.pb(s);
    if(s==t)return true;
    for(auto it:v[s]){
        if(it!=f){
            if(dfs(it,t,s))return true;
        }
    }
    stk.pop_back();
    return false;
}
int dfs2(int x,int f){
    int res=1;
    for(auto it:v[x]){
        if(it!=f&&!circle[it]){
            res+=dfs2(it,x);
        }
    }
    return res;
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear(),f[i]=i,circle[i]=0;   stk.clear();
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int a=Find(x),b=Find(y);
        if(a==b){
            dfs(x,y,x);
            for(auto it:stk)circle[it]=1;//printf("?%d\n",it);
        }
        else{
            v[x].pb(y);
            v[y].pb(x);
            f[a]=b;
        }
    }
    LL ans=n;
    ans*=(n-1);
    //ans/=2;
     //  printf("%lld\n",ans);
    
    for(auto it:stk){
        LL tot=dfs2(it,it);
     //   printf("%lld\n",tot);
        ans+=tot*(n-tot);
    }
     //  printf("%lld\n",ans);
    ans/=2;
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}