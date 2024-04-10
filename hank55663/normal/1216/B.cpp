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
int main(){
    int n;
    scanf("%d",&n);
    pii p[1005];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        p[i]=mp(x,i+1);
    }
    sort(p,p+n);
    reverse(p,p+n);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=p[i].x*i+1;
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++){
        printf("%d ",p[i].y);
    }
    printf("\n");
}