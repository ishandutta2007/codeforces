#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
vector<int> v[200005];
int vis[200005];
int ans[200005];
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]+i<=n)v[a[i]+i].pb(i);
        if(i-a[i]>=1)v[i-a[i]].pb(i);
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(a[i]&1)q.push(i);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            if(ans[it]==0&&a[it]%2==0){
                ans[it]=ans[x]+1;
                q.push(it);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(a[i]%2==0)q.push(i);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            if(ans[it]==0&&a[it]%2==1){
                if(a[x]%2==0)ans[it]=1;
                else ans[it]=ans[x]+1;
                q.push(it);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(ans[i]==0)ans[i]=-1;
        printf("%d ",ans[i]);
    }
    printf("\n");
}