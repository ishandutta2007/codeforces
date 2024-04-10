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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    LL cnt[1000005];
    MEM(cnt);
    for(int i = 2;i<1000005;i++){
        int r=min(i-b,b),l=max(i-c,a);
        cnt[i]=max(r-l+1,0);
    }
    for(int i = 1000000;i>=0;i--){
        cnt[i]+=cnt[i+1];
    }
    LL ans=0;
    for(int i = c;i<=d;i++)
        ans+=cnt[i+1];
    printf("%lld\n",ans);
}

/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/