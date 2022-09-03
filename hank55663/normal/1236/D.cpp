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
vector<int> r[100005],c[100005];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        r[x].pb(y);
        c[y].pb(x);
    }
    for(int i = 1;i<=n;i++)r[i].pb(0),r[i].pb(m+1),sort(r[i].begin(),r[i].end());
    for(int i = 1;i<=m;i++)c[i].pb(0),c[i].pb(n+1),sort(c[i].begin(),c[i].end());
    int nowx=1,nowy=0;
    LL tot=0;
    int lx=0,rx=n+1,ly=0,ry=m+1;
    while(true){
        int x,y;
        y=min(*upper_bound(r[nowx].begin(),r[nowx].end(),nowy),ry)-1;
        tot+=y-nowy;
        if(y==nowy)break;
        nowy=y;
        lx=nowx;
        x=min(*upper_bound(c[nowy].begin(),c[nowy].end(),nowx),rx)-1;
        tot+=x-nowx;
        if(x==nowx)break;
        nowx=x;
        ry=nowy;
        y=max(*(upper_bound(r[nowx].begin(),r[nowx].end(),nowy)-1),ly)+1;
        tot+=nowy-y;
        if(nowy==y)break;
        nowy=y;
        rx=nowx;
        x=max(*(upper_bound(c[nowy].begin(),c[nowy].end(),nowx)-1),lx)+1;
        tot+=nowx-x;
        if(nowx==x)break;
        nowx=x;
        ly=nowy;
    }
   // printf("%lld\n",tot);
    if(tot==(LL)n*m-k)printf("Yes\n");
    else printf("No\n");

}