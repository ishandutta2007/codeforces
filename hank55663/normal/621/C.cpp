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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000

bool solve(){;
    int n,a;
    scanf("%d %d",&n,&a);
    double sum=0;
    pii p[100005];
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        p[i]=mp(l,r);
    }
    for(int i = 0;i<n;i++){
        LL aa=(p[i].y-p[i].x+1)-p[i].y/a+(p[i].x-1)/a;
        LL bb=(p[(i+1)%n].y-p[(i+1)%n].x+1)-p[(i+1)%n].y/a+(p[(i+1)%n].x-1)/a;
        LL tot=(p[i].y-p[i].x+1);
        tot*=(p[(i+1)%n].y-p[(i+1)%n].x+1);
        //printf("%lld %lld %lld\n",aa,bb,tot);
        sum+=(1-aa*bb*1.0/tot)*2000;
    }
    printf("%.12f\n",sum);
    return true;
}
int main(){
    int t=1;00000;
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