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
vector<int> v[1005];
LL a[1005];
int degree[1005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
        v[i].clear();
        degree[i]=0;
    }
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        degree[y]++;
    }
    int sum=2*n;
    for(int i = 0;i<2*n;i++){
        vector<int> tmp;
        for(int j = 1;j<=n;j++){
            if(a[j])tmp.pb(j);
        }
        if(tmp.empty()){
            printf("%d\n",i);
            return;
        }
        for(auto it:tmp){
            a[it]--;
            for(auto it2:v[it])a[it2]++;
        }
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(degree[i]==0)q.push(i);
    }
    const int mod=998244353;
    int last=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        last=x;
        for(auto it:v[x]){
            a[it]+=a[x];
            a[it]%=mod;
            if(--degree[it]==0)q.push(it);
        }
    }
    printf("%lld\n",(sum+a[last])%mod);
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/