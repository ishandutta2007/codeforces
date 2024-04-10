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
int mod=999991231;
int base=123;
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    char c[2005][205];
    LL hash[2005];
    for(int i=0;i<n;i++){
        scanf("%s",c[i]);
    }
    map<LL,int> ma;
    for(int i=0;i<=n-m;i++){
        LL hash=0;
        for(int j=i;j<i+m;j++){
            for(int k=0;k<m;k++){
                hash*=base;
                hash+=c[j][k];
                hash%=mod;
            }
        }
       // printf("%lld ",hash);
        ma[hash]=i+1;
    }
   // printf("\n");
    char c1[205][2005];
    for(int i=0;i<m;i++){
        scanf("%s",c1[i]);
    }
    for(int i=0;i<=n-m;i++){
        LL hash=0;
        for(int k=0;k<m;k++)
            for(int j=i;j<i+m;j++){
                hash*=base;
                hash+=c1[k][j];
                hash%=mod;
            }
        if(ma.find(hash)!=ma.end()){
            printf("%d %d\n",ma[hash],i+1);
            return 0;
        }
       // printf("%lld ",hash);
    }
    printf("\n");
}