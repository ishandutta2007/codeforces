#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int cnt[10];
LL fra[20];
LL dfs(int i,int sum,LL tot,int tag){
    if(i==10){
        return fra[sum]/tot;
    }
    if(!cnt[i])
        return dfs(i+1,sum,tot,tag);
    LL ret=0;
    if(tag&&i==0)
    for(int j=0;j<=cnt[i];j++){
        ret+=dfs(i+1,sum+j,tot*fra[j],tag);
    }
    else
    for(int j=1;j<=cnt[i];j++){
        ret+=dfs(i+1,sum+j,tot*fra[j],tag);
    }
    return ret;
}
int main(){
    MEM(cnt);
    char c[20];
    scanf("%s",c);
    int need=0;
    for(int i=0;c[i]!=0;i++){
        cnt[c[i]-'0']++;
    }
    fra[0]=1;
    for(int i=1;i<20;i++)
    fra[i]=fra[i-1]*i;
    LL ans=dfs(0,0,1,0);
   // printf("%d\n",ans);
    if(cnt[0]){
        cnt[0]--;
        ans-=dfs(0,0,1,1);
    }
    printf("%lld\n",ans);
    return 0;
}