#include<bits/stdc++.h>
using namespace std;
#pragma optimizer(-Ofast)
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
#define pdd pair<double,double>
#define cpdd const pdd
#define rank Rank
#define MXN 15000

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int s,i,e;
        scanf("%d %d %d",&s,&i,&e);
        int tot = s+i+e;
        int Max=min((tot-1)/2,i+e);
        printf("%d\n",max(Max-i+1,0));
    }
    return 0;
}