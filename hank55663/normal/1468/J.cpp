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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
bool solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1;i<=n;i++)f[i]=i;
    vector<pair<int,pii>> edge;// edge[200005];
    vector<pii> edge2;
    int Min=1e9+7;
    for(int i = 0;i<m;i++){
        int x,y,s;
        scanf("%d %d %d",&x,&y,&s);
        if(s>k)edge.pb(mp(s-k,mp(x,y)));
        //else if(s==k)equal.pb(mp(x,y));
        else edge2.pb(mp(x,y)),Min=min(Min,k-s);
    }
    int cnt=0;
    for(auto it:edge2){
        int a=Find(it.x);
        int b=Find(it.y);
        if(a!=b){
            f[a]=b;
            cnt++;
        }
    }
    LL ans=1e18;
    if(cnt==n-1)ans=Min;
    LL need=0;
    sort(edge.begin(),edge.end());
    for(auto it:edge){
        int a=Find(it.y.x);
        int b=Find(it.y.y);
        if(a!=b){
            need+=it.x;
            f[a]=b;
            cnt++;
            if(cnt==n-1){
                ans=min(ans,need);
           // printf("%d %d\n",need,it.x);
            }
        }
        if(cnt==n-1){
            ans=min(ans,need+it.x);
           // printf("%d %d\n",need,it.x);
        }
    }
    printf("%lld\n",ans);
    return true;
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/