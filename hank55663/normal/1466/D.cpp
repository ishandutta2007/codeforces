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
int degree[100005];
bool solve(){
    int n;
    scanf("%d",&n);
    fill(degree,degree+n+1,0);
    LL w[100005];
    for(int i = 1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        degree[x]++;
        degree[y]++;
    }
    priority_queue<pii> pq;
    LL ans=0;
    for(int i = 1;i<=n;i++){
        degree[i]--;
        if(degree[i])pq.push(mp(w[i],degree[i]));
        ans+=w[i];
    }
    printf("%lld ",ans);
    for(int i = 2;i<n;i++){
        pii p=pq.top();
        pq.pop();
        ans+=p.x;
        p.y--;
        if(p.y)pq.push(p);
        printf("%lld ",ans);
    }
    printf("\n");
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