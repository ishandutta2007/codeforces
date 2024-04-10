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
int mod=1e9+7;
bool solve(){
    int n;
    scanf("%d",&n);
    int h[1000005];
    LL pre=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    LL ans=0;
    for(int i = 1;i<=n;i++){
        ans+=pre*(min(h[i],h[i-1])-1)+h[i]-1;
        ans%=mod;
        pre=pre*(min(min(h[i],h[i-1]),h[i+1])-1)+min(h[i],h[i+1])-1;
        pre%=mod;
    }
    printf("%lld\n",ans);
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}