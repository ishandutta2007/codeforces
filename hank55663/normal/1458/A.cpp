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
    int n,m;
    scanf("%d %d",&n,&m);
    LL gcd=0;
    LL a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i = 2;i<=n;i++){
        gcd=__gcd(gcd,abs(a[i]-a[1]));
    }
    for(int i = 1;i<=m;i++){
        LL x;
        scanf("%lld",&x);
        printf("%lld ",__gcd(a[1]+x,gcd));
    }
    printf("\n");
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/