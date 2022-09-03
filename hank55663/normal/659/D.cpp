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
int vis[200005];
bool solve(){
    int n;
    scanf("%d",&n);
    pii p[1005];
    for(int i = 0;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    int cnt=0;
    for(int i = 1;i<n;i++){
        if(p[i-1].y<p[i].y&&p[i].x>p[i+1].x)cnt++;
        else if(p[i-1].x<p[i].x&&p[i].y<p[i+1].y)cnt++;
        else if(p[i-1].y>p[i].y&&p[i].x<p[i+1].x)cnt++;
        else if(p[i-1].x>p[i].x&&p[i].y>p[i+1].y)cnt++;
        else{
           // printf("%d\n",i);
        }
    }
    printf("%d\n",cnt);
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}