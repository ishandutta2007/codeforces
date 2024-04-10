#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main(){
    int k;
    scanf("%d",&k);
    printf("3 3\n");
    printf("%d %d 0\n",131072+k,131072);
    printf("%d %d %d\n",k,131072+k,k);
    printf("0 %d %d\n",k,k);
}