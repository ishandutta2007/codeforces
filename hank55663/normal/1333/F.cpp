#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
vector<int> v[500005];
int cnt[500005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j+=i){
            v[i].pb(j);
        }
    }
    fill(cnt,cnt+n+1,1);
    int tot=n;
    int ans[500005];
    int now=n,val=1;
    for(int i =n;i>=2;i--){
        while(tot-val+1>=i){
            for(auto it:v[now])cnt[it]=0;
            cnt[now]=1;
            tot=tot-val+1;
            val=0;
            now--;
            for(auto it:v[now])val+=cnt[it];
           // printf("%d %d %d\n",val,i,now);

        }
        ans[i]=now;
    }
    for(int i = 2;i<=n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}
/*

*/