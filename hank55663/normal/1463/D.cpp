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
bool solve(){
    int n;
    scanf("%d",&n);
    int cnt[400005];
    fill(cnt,cnt+2*n+5,-1);
    cnt[0]=0;
    int b[200005];
    for(int i = 0;i<n;i++)scanf("%d",&b[i]),cnt[b[i]]=1;
    int Max=0;
    for(int i = 1;i<=2*n;i++){
        cnt[i]+=cnt[i-1];
        Max=max(Max,cnt[i]);
    }
    fill(cnt,cnt+2*n+5,-1);
    for(int i = 0;i<n;i++)cnt[b[i]]=1;
    int Max2=0;
    cnt[2*n+1]=0;
    for(int i =2*n;i>=1;i--){
        cnt[i]+=cnt[i+1];
        Max2=max(Max2,cnt[i]);
    }
    Max2=n-Max2;
   // printf("%d %d\n",Max,Max2);
    printf("%d\n",Max2-Max+1);
    return true;
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}