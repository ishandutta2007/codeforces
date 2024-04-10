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
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[200005];
        LL sum=0,val=0;
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            val^=a[i];
        }
        if(sum==val*2){
            printf("0\n\n");
        }
        else{
            printf("2\n");
            sum+=val;
            printf("%lld %lld\n",val,sum);
            val^=val;
            val^=sum;
            sum+=sum;
            assert(sum==val*2);
            
        }
    }
}
/*
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/