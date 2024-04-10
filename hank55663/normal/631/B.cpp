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
using namespace std;
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
int mod=1e9+7;
bool solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int rc[5005],cc[5005];
    int rt[5005],ct[5005];
    MEM(rc);
    MEM(cc);
    MEM(rt);
    MEM(ct);
    for(int i = 1;i<=k;i++){
        int op;
        scanf("%d",&op);
        int r,a;
        scanf("%d %d",&r,&a);
        if(op==1)rc[r]=a,rt[r]=i;
        else cc[r]=a,ct[r]=i;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(ct[j]>rt[i])printf("%d ",cc[j]);
            else printf("%d ",rc[i]);
        }
        printf("\n");
    }
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}