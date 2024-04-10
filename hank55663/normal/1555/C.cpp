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
void solve(){
    int m;
    scanf("%d",&m);
    LL a[2][100005];
    LL pre[100005],suf[100005];
    LL ans=0;
    for(int i = 0;i<2;i++){
        for(int j = 1;j<=m;j++){
            scanf("%lld",&a[i][j]);
            ans+=a[i][j];
        }
    }
    pre[0]=0;
    suf[m+1]=0;
    for(int j = 1;j<=m;j++)pre[j]=pre[j-1]+a[1][j];
    for(int j =m;j>=1;j--)suf[j]=suf[j+1]+a[0][j];
    
    for(int j = 1;j<=m;j++){
        //printf("%d %d\n",suf[j+1],pre[j-1]);
        ans=min(ans,max(suf[j+1],pre[j-1]));
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/