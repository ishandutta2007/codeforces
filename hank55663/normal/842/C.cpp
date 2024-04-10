#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
vector<int> E[200005];
int a[200005];
int ans[200005];
void dfs(int x,int f,vector<int> v,int now){
    for(auto &it:v){
        it=__gcd(it,a[x]);
    }
    v.pb(now);
    sort(v.begin(),v.end());
    int cnt=unique(v.begin(),v.end())-v.begin();
    while(v.size()>cnt)
    v.pop_back();
    now=__gcd(now,a[x]);
   // printf("%d ",x);
   // for(auto it:v)
  //  printf("%d ",it);
   // printf("%d\n",now);
    ans[x]=max(v.back(),now);
    for(auto it:E[x]){
        if(it!=f){
            dfs(it,x,v,now);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        E[x].pb(y);
        E[y].pb(x);
    }
    dfs(1,0,vector<int>(),0);
    for(int i =1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/