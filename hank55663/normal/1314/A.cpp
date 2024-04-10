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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
map<int,int> m;
int Find(int x){
    if(m.find(x)==m.end())return m[x]=x;
    return m[x]=Find(m[x]);
}
int main(){
    int n;
    scanf("%d",&n);
    pii p[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&p[i].y);
        //int x,y;
        //scanf("%d %d",&x,&y);
        //p[i]=mp(y,x);
    }
    for(int i = 0;i<n;i++)
    scanf("%d",&p[i].x);
    sort(p,p+n);
    reverse(p,p+n);
    LL ans=0;
    for(int i = 0;i<n;i++){
        int x=Find(p[i].y);
        ans+=(LL)(x-p[i].y)*p[i].x;
        m[x]=x+1;
    }
    printf("%lld\n",ans);
    //set<int> s;
    
    return 0;
}