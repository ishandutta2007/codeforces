#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    a=min(a,b);
    LL res=1;
    for(int i =1;i<=a;i++)
        res*=i;
    printf("%lld\n",res);
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/