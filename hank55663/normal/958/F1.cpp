#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main() {
    int n,m;
    int hav[105][105];
    MEM(hav);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        for(int j=1;j<=m;j++)
        hav[i][j]=hav[i-1][j];
        hav[i][a]++;
    }
    int cnt[105];
    int tot=0;
    for(int i=1;i<=m;i++){
        scanf("%d",&cnt[i]);
        tot+=cnt[i];
    }
   // printf("%d\n",tot);
    for(int i=tot;i<=n;i++){
        int ok=1;
        for(int k=1;k<=m;k++){
            if(hav[i][k]-hav[i-tot][k]!=cnt[k]){
                ok=0;
            }
           // printf("%d ",hav[i][k]-hav[i-tot][k]);
        }
       // printf("\n");
        if(ok){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}