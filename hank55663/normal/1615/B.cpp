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
#define index Index
int cnt[200005][20];
void solve(){
    int l,r;
    scanf("%d %d",&l,&r);
    int ans=(r-l+1);
    for(int i = 0;i<20;i++){
        ans=min(ans,cnt[r][i]-cnt[l-1][i]);
    }
    printf("%d\n",ans);
}
int main(){
    for(int i = 1;i<=200000;i++){
        for(int j = 0;j<20;j++){
            cnt[i][j]=cnt[i-1][j];
            if(i&(1<<j));
            else 
            cnt[i][j]++;
        }
    }
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/