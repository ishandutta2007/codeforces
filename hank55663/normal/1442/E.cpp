#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[200005];
int degree[200005];
int a[200005];
void solve(){   
    int n;
    scanf("%d",&n);
    for(int i = 0;i<=n;i++)v[i].clear(),degree[i]=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==2)a[i]=0;
        else if(a[i]==0)a[i]=2;
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        degree[x]++;
        degree[y]++;
    }
    queue<int> q[3];
    for(int i = 1;i<=n;i++){
        if(degree[i]<=1)q[a[i]].push(i);
    }
    int ans=0;
    int cnt=n;
  
    while(q[2].size()){
        int x=q[2].front();
        q[2].pop();
        cnt--;
        for(auto it:v[x]){
            if(--degree[it]==1){
                q[a[it]].push(it);
            }
        }
    }
     
    int now=0;
    if(q[0].empty()){
        now=1;
    }
    while(cnt){
      //  printf("%d %d %d\n",ans,q[now].size(),q[2].size());
     //  printf("%d %d %d %d\n",q[0].size(),q[1].size(),q[2].size(),now);
        ans++;
        while(q[now].size()||q[2].size()){
            int x;
            if(q[now].empty()){
                x=q[2].front();
                q[2].pop();
            }
            else{
                x=q[now].front();
                q[now].pop();
            }
            cnt--;
            for(auto it:v[x]){
                if(--degree[it]==1){
                    q[a[it]].push(it);
                }
            }
        }
        now^=1;
    }
    int ans1=max(ans,1);
    for(int i = 1;i<=n;i++)degree[i]=v[i].size();
    for(int t=0;t<3;t++)
    while(q[t].size())q[t].pop();
     for(int i = 1;i<=n;i++){
        if(degree[i]<=1)q[a[i]].push(i);
    }
    ans=0;
    cnt=n;
      while(q[2].size()){
        int x=q[2].front();
        q[2].pop();
        cnt--;
        for(auto it:v[x]){
            if(--degree[it]==1){
                q[a[it]].push(it);
            }
        }
    }
     
    now=1;
    if(q[1].empty()){
        now=0;
    }
    while(cnt){
      //  printf("%d %d %d\n",ans,q[now].size(),q[2].size());
     //  printf("%d %d %d %d\n",q[0].size(),q[1].size(),q[2].size(),now);
        ans++;
        while(q[now].size()||q[2].size()){
            int x;
            if(q[now].empty()){
                x=q[2].front();
                q[2].pop();
            }
            else{
                x=q[now].front();
                q[now].pop();
            }
            cnt--;
            for(auto it:v[x]){
                if(--degree[it]==1){
                    q[a[it]].push(it);
                }
            }
        }
        now^=1;
    }
    ans=max(ans,1);
    printf("%d\n",min(ans,ans1));
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