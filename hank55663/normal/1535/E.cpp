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
#define last Last
#define MXN 200005
const int mod=1e9+7;
int p[20][300005];
int a[300005],c[300005];
void solve(){
    int q;
    scanf("%d %d %d",&q,&a[0],&c[0]);
    for(int i = 1;i<=q;i++){
        int t;
        scanf("%d",&t);
        if(t==1){
            scanf("%d %d %d",&p[0][i],&a[i],&c[i]);
            for(int j = 1;j<20;j++){
                p[j][i]=p[j-1][p[j-1][i]];
            }
        }
        else{
            int v,w;
            scanf("%d %d",&v,&w);
            LL ans=0;
            int sum=0;
            while(a[v]&&w){
                LL now=v;
                for(int i = 19;i>=0;i--){
                    if(a[p[i][now]])now=p[i][now];
                }
                int add=min(w,a[now]);
                a[now]-=add;
                w-=add;
                sum+=add;
                ans+=c[now]*1ll*add;
            }
            printf("%d %lld\n",sum,ans);
            fflush(stdout);
        }
    }
} 
/*
C[n-(k-1)*(i-1)][n-i-(k-1)*(i+1)]
//[n-k*i+i-k+1][i]
*/
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/