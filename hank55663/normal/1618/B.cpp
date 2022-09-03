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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    char c[105][5];
    for(int i = 0;i<n-2;i++)scanf("%s",c[i]);
    int ok=0;
    printf("%s",c[0]);
    for(int i =1;i<n-2;i++){
        if(c[i][0]!=c[i-1][1])printf("%c",c[i][0]),ok=1;
        printf("%c",c[i][1]);
    }
    if(!ok)printf("b");
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
ACBABC
ACBCAB
ACABCB
*/