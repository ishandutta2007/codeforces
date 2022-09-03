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
    int n,d,e;
    scanf("%d %d %d",&n,&d,&e);
    int ans=n;
    for(int i = 0;i*d<=n;i++){
        int dd=i;
        int ee=(n-i*d)/e;
        int num=n-dd*d-ee*e;
        num+=ee%5*e;
        ans=min(ans,num);
    }
    printf("%d\n",ans);
}