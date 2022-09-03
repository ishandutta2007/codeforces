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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,r,b;
    scanf("%d %d %d",&n,&r,&b);
    int x=r/(b+1);
    int more=r%(b+1);
    for(int i = 0;i<x;i++){
        printf("R");
        r--;
    }
    if(more)printf("R"),r--,more--;
    for(int i = 0;i<b;i++){
        printf("B");
        for(int j  =0;j<x;j++)printf("R"),r--;
        if(more)printf("R"),r--,more--;
    }
    printf("\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP
*/