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
#define last Last
#define MXN 200005
const int mod=1e9+7;
void solve(){
    LL c,d,a,b;
    scanf("%lld %lld %lld %lld",&c,&d,&a,&b);
    if(a==b){
        printf("%lld\n",min(c/a,d/a));
        return ;
    }
    LL x=(c*a-b*d)/(a*a-b*b);
    LL ans=0;
    for(int i = max(x,0ll);i<=max(x+100,100ll);i++){
        LL cc=c-a*i,dd=d-b*i;
        if(cc>=0&&dd>=0){
            ans=max(ans,i+min(cc/b,dd/a));
        }
    }
   // printf("%lld\n",x);
    LL y=(a*d-c*b)/(a*a-b*b);
     for(int i = max(y,0ll);i<=max(y+100,100ll);i++){
        LL cc=c-b*i,dd=d-a*i;
        if(cc>=0&&dd>=0){
            ans=max(ans,i+min(cc/a,dd/b));
        }
    }
    printf("%lld\n",ans);

}
/*
ax+by<=c;
bx+ay<=d;
*/
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/