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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
#define N 6000005
#define rank Rank
int main(){
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    int cnt=0;
    char c[300005];
    scanf("%s",c);
    for(int i = 0;i<n;i++){
        if(c[i]=='0'&&(i==0||c[i-1]=='1'))cnt++;    
    }
    LL ans=1e18;
    //printf("%d\n",cnt);
    for(int i = 0;i<cnt;i++){
        ans=min(ans,(LL)y*(cnt-i)+(LL)x*i);
    }
    if(cnt==0)ans=0;
    printf("%lld\n",ans);
}