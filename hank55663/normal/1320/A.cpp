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
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    map<int,LL> m;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        m[a[i]-i]+=a[i];
    }
    LL ans=0;
    for(auto it:m){
        ans=max(ans,it.y);
    }
    printf("%lld\n",ans);

}