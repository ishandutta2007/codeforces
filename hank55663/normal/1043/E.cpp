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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
vector<int> v[300005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    pll p[300005];
    int sc[300005];
    LL pre[300005];
    LL sum=0;
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        sc[i]=x-y;
        sum+=y;
    }
    sort(sc+1,sc+n+1);
    pre[0]=0;
    for(int i = 1;i<=n;i++){
        pre[i]=pre[i-1]+sc[i];
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i =1;i<=n;i++){
        LL score=p[i].x*(n-1)+sum-p[i].y;
        LL tmp=p[i].y-p[i].x;
        int index=lower_bound(sc+1,sc+n+1,-tmp)-sc-1;
        score+=tmp*index+pre[index];
        for(auto it:v[i]){
            score-=min(p[i].x+p[it].y,p[i].y+p[it].x);
        }
        printf("%lld ",score);
    }
    printf("\n");
}