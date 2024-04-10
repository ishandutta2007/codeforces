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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define next Next
int main() {
    int q;
    scanf("%d",&q);
    while(q--){
        LL a[3];
        for(int i = 0;i<3;i++)
            scanf("%lld",&a[i]);
        printf("%lld\n",(a[0]+a[1]+a[2])/2);
    }
}