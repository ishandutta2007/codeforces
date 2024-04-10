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
#define MXN 1500005
//#define next Next
#define index Index
#define rank Rank
#define context Context
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n;
        scanf("%lld",&n);
        string s="1";
        for(int j = 0;j<45000;j++){
            s+='3';
        }
        int cnt[45005];
        MEM(cnt);
        for(LL j = 45000;j>1;j--){
            while(n>=(j)*(j-1)/2){
                n-=(j)*(j-1)/2;
                cnt[j]++;
            }
            //printf("%d %d\n",j,n);
        }
        for(int j=0;j<=45000;j++){
            printf("%c",s[j]);
            while(cnt[j]--){
                printf("7");
            }
        }
        printf("\n");
        assert(n==0);
    }
    return 0;
}
/*
1 3 6 10 15
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */