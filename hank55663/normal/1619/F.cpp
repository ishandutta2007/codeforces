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
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int extra=n%m*(n/m+1);
    int now=0;
    for(int i  =0;i<k;i++){
        int vis[200005];
        fill(vis,vis+n+1,0);
        int x=now;
        for(int j=0;j<n%m;j++){
            printf("%d",n/m+1);
            for(int k = 0;k<n/m+1;k++){
                printf(" %d",x+1);
                vis[x]=1;
                x=(x+1)%n;
            }
            printf("\n");
        }
        x=0;
        for(int j = n%m;j<m;j++){
            printf("%d",n/m);
            for(int k = 0;k<n/m;k++){
                while(vis[x])x++;
                printf(" %d",x+1);
                x=(x+1)%n;
            }
            printf("\n");
        }

        now=(now+extra)%n;
    }
            printf("\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}