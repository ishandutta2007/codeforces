#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
vector<int> v[200005];
LL a[200005];
LL val=0;
vector<int> ans,ans2;
void dfs(int x){
    for(auto it:v[x]){
        dfs(it);
        if(a[it]>0)
        a[x]+=a[it];
    }
    //a[x]=max(a[x],0);
  
    if(a[x]>0){
          val+=a[x];
        ans.pb(x);
    }
    else{
        val+=a[x];
        ans2.pb(x);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
    vector<int> root;
    for(int i= 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==-1)root.pb(i);
        else v[x].pb(i);
    }
    for(auto it:root){
       // printf("? %d\n",it);
        dfs(it);
    }
    printf("%lld\n",val);
    for(auto it:ans)printf("%d ",it);
    reverse(ans2.begin(),ans2.end());
    for(auto it:ans2)printf("%d ",it);
    printf("\n");
}