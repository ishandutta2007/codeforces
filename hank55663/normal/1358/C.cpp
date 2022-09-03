#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL x1,x2,y1,y2;
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        printf("%lld\n",(x2-x1)*(y2-y1)+1);
    }
}
/*
2 11 14
9 3


000111222
001112220
*/