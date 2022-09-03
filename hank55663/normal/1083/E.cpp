/*#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
using namespace std;
typedef long long LL;
LL dp[1000005];
pair<pll,LL> p[1000005];
bool cmp(const pair<pll,LL> &a,const pair<pll,LL> &b){
    if(a.x.x!=b.x.x)
    return a.x.y>b.x.y;
    else
    return a.x.x<b.x.x;
}
int main(){
    int n;
    scanf("%d",&n);
   // printf("%d %d\n",(-3)/2,3/(-2));
    for(int i=1;i<=n;i++){
        LL x,y,a;
        scanf("%lld %lld %lld",&x,&y,&a);
        p[i]=mp(mp(x,y),a);
    }
    sort(p+1,p+n+1,cmp);
    p[0]=mp(mp(0,1000000001),0);
    dp[0]=0;
    vector<pair<LL,Line> >v;
    v.pb(mp(-1000000000000000000ll,mp(0,0)));
    for(int i=1;i<=n;i++){
        Line l=(lower_bound(v.begin(),v.end(),mp(-p[i].x.y,mp(1000000000000ll,1000000000000ll)))-1)->y;
      //  printf("%d %d\n",l.x,l.y);
        dp[i]=max(l.x*-p[i].x.y+l.y-p[i].y+p[i].x.x*p[i].x.y,dp[i-1]);
        Line l1=mp(p[i].x.x,dp[i]);
        LL x=0;
        while(!v.empty()){
            Line l2=v.back().y;
            if(l2.x==l1.x){
                v.pop_back();
                continue;
            }
            x=(l1.y-l2.y)/(l2.x-l1.x);
            if(x<=v.back().x){
                v.pop_back();
            }
            else{
                break;
            }
        }
        //printf("%d %d %d %d\n",dp[i],x,l1.x,l1.y);
        v.pb(mp(x,l1));
    }
    printf("%lld\n",dp[n]);
}