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
#define double long double
using namespace std;
vector<int> v[200005];
int val[200005];
int a[200005];
int ans=0;
vector<int> stk;
set<int> dfs(int x,int f){
    val[x]=val[f]^a[x];
   // printf("%d %d\n",x,val[x]);
    set<int> s;
    s.insert(val[x]);
    int ok=1;
 //   if(val[x]==0)ok=0;
    for(auto it:v[x]){
        if(it!=f){
            //stk.pb(a[it]);
            set<int> tmp=dfs(it,x);
            if(tmp.size()>s.size())swap(s,tmp);//swap(stk.back(),stk[stk.size()-2]);
            for(auto it:tmp){
                if(s.find(it^a[x])!=s.end())ok=0;
               // s.insert(it);
            }
            for(auto it:tmp)s.insert(it);
            //stk.pop_back();
        }
    }
    if(!ok)s.clear(),ans++;
    return s;
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    stk.pb(a[1]);
    dfs(1,0);
    printf("%d\n",ans);
}
int main(){
    int t=1;000;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/