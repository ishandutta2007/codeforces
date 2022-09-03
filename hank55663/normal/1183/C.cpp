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
#define less Less
#define N (1<<20)
typedef complex<double> C;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int k,n,a,b;
        scanf("%d %d %d %d",&k,&n,&a,&b);
        LL Max=n+1,Min=-1;
        while(Max>Min+1){
            LL mid=(Max+Min)/2;
            if(k-(mid*a+(n-mid)*b)<=0){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        printf("%lld\n",Min);
    }
}
/*
1 
2 6 
3 5 
4
*/