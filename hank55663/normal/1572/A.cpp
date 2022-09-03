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
const int mod=998244353;
vector<int> v[200005];
int degree[200005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        v[i].clear();
        degree[i]=0;
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j = 1;j<=k;j++){
            int x;
            scanf("%d",&x);
            v[x].pb(i);
            degree[i]++;
        }
    }
    set<int> s;
    for(int i = 1;i<=n;i++){
        if(degree[i]==0)s.insert(i);
    }
    int now=n+1;
    int ans=0;
    int cnt=0;
    while(s.size()){
        if(s.lower_bound(now)==s.end()){
            now=*s.begin();
            ans++;
        }
        else{
            now=*s.lower_bound(now);
        }
       // printf("%d\n",now);
        s.erase(now);
        cnt++;
        for(auto it:v[now]){
            if(--degree[it]==0){
                s.insert(it);
            }
        }
    }
   // printf("%d %d\n",cnt,n);
    if(cnt==n)
    printf("%d\n",ans);
    else printf("-1\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
000010000
001010000
001010100
001011100

1 1 2
1 1 2 1
2 1
2


XOXOXOXOOXOXXOXOXOXOOXOX
*/