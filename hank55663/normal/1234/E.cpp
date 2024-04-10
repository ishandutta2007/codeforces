#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
LL val[200005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x[200005];
    for(int i = 0;i<m;i++){
        scanf("%d",&x[i]);
    }
    for(int i = 1;i<m;i++){
        if(x[i]==x[i-1])continue;
        val[1]+=abs(x[i]-x[i-1]);
        int l=min(x[i],x[i-1]),r=max(x[i],x[i-1]);
        val[l]-=abs(x[i]-x[i-1]);
        val[l]+=r-1;
        val[l+1]-=r-1;
        val[l+1]+=abs(x[i]-x[i-1])-1;
        val[r]-=abs(x[i]-x[i-1])-1;
        val[r]+=l;
        val[r+1]-=l;
        val[r+1]+=abs(x[i]-x[i-1]);
    }
    LL now=0;
    for(int i = 1;i<=n;i++){
        now+=val[i];
        printf("%lld ",now);
    }
    printf("\n");
    return 0;
}