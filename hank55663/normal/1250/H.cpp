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
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL a,b,n,s;
        scanf("%lld %lld %lld %lld",&a,&b,&n,&s);
        int x=s/n,y=s%n;
        y+=max(x-a,0ll)*n;
        x-=max(x-a,0ll);
        if(x<=a&&y<=b)printf("YES\n");
        else printf("NO\n");
    }
}