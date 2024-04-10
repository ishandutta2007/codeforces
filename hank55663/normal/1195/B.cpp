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
#define MXN 10005
#define N (1<<20)
int main(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    LL Max=n,Min=0;
    while(Max>Min+1){
        LL mid=(Max+Min)/2;
        if(mid*(mid+1)/2-(n-mid)>=k){
            Max=mid;
        }
        else{
            Min=mid;
        }
    }
    printf("%lld\n",n-Max);
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/