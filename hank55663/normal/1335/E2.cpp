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
#define pi acosl(-1)
//#define N 524288
#define ld long double
using namespace std;
int pre[205][200005];
int a[200005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 0;i<=n;i++){
            for(int j=0;j<205;j++)pre[j][i]=0;
        }
        
        for(int i = 1;i<=n;i++){
            int x=rand()%200+1;
            scanf("%d",&x);
            for(int j=0;j<=200;j++)pre[j][i]=pre[j][i-1];
            pre[x][i]++;
            a[i]=x;
        }
        int ans=0;
        for(int i = 0;i<205;i++)ans=max(ans,pre[i][n]);
        for(int i = 1;i<=n;i++){
            int cnt=pre[a[i]][i];
            if(cnt*2>pre[a[i]][n])continue;
            int r=lower_bound(pre[a[i]]+1,pre[a[i]]+n+1,pre[a[i]][n]-cnt+1)-pre[a[i]]-1;
        //    printf("%d\n",r);
            int Max=0;
            for(int j=0;j<205;j++){
                if(j!=a[i])
                Max=max(Max,pre[j][r]-pre[j][i]);
            }
            ans=max(ans,Max+cnt*2);
        }
        printf("%d\n",ans);
    }

}
/*
00 00
01 10
10 11
11 01
2 1 3 0 2
3 1 3 0 2
3 2 3 0 2
3 2 4 0 2
3 2 4 1 2
3 2 4 1 3
*/