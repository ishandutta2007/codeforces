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
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int k[300005];
    int c[300005];
    for(int i = 0;i<n;i++)scanf("%d",&k[i]);
    sort(k,k+n);
    for(int i = 1;i<=m;i++)scanf("%d",&c[i]);
    LL ans=0;
    int now=1;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i = 0;i<n;i++){
        if(pq.empty()||(pq.top()>c[now]&&now!=m+1)){
            ans+=c[now++];
        }
        else{
            ans+=pq.top();
            pq.pop();
        }
        pq.push(c[k[i]]);
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