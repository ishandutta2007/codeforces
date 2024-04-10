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
#define EPS 1e-4
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 200005
int main(){
    int b,g,n;
    scanf("%d %d %d",&b,&g,&n);
    int ans=0;
    for(int i = 0;i<=b&&i<=n;i++){
        if(n-i<=g)ans++;
    }
    printf("%d\n",ans);
}