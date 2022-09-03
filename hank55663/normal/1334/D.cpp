#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
LL cal(LL i,LL n){
    if(i==n*(n-1)+1){
        return 1;
    }
    i--;
    int Min=0,Max=n;
    while(Min+1<Max){
        int mid=(Max+Min)/2;
        if((n-1+n-mid)*(mid)>i)Max=mid;
        else Min=mid;
    }
    //printf("!%d ",Min);
    i-=(n-1+n-Min)*Min;
    if(i%2==0){
        return Min+1;
    }
    else{
        return Min+1+(i+1)/2;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,l,r;
        scanf("%lld %lld %lld",&n,&l,&r);
        for(LL i=l;i<=r;i++){
            printf("%d ",cal(i,n));
        }
        printf("\n");
    }
}
/*
1 2 1 3 1 4 1....1 n 2 3 2 4 2 5 2 6....2 n
*/