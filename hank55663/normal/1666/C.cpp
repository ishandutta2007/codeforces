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
void solve(){
    pii p[3];
    for(int i = 0;i<3;i++){
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    sort(p,p+3);
    int Max=max(p[0].y,max(p[1].y,p[2].y)),Min=min(p[0].y,min(p[1].y,p[2].y));
    printf("3\n");
    printf("%d %d %d %d\n",p[1].x,Min,p[1].x,Max);
    printf("%d %d %d %d\n",p[0].x,p[0].y,p[1].x,p[0].y);
    printf("%d %d %d %d\n",p[2].x,p[2].y,p[1].x,p[2].y);
}
int main(){
    int t=1;00000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/