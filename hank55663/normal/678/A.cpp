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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d\n",(n/k+1)*k);
}
/*
[1,2,4,3,5,6]
concat(sorted([4,2,1]),sorted([5,3,6]))
concat(shuffle([2,1]),shuffle([2,3]))
concat(shuffle([2,1,3]),shuffle([3]))
1 3 4

*/