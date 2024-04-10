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
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[200005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    LL Max=2e9+1,Min=0;
    while(Max>Min+1){
        LL mid=(Max+Min)/2;
        LL sum=0;
        for(int j = n/2;j<n;j++)
            if(mid>a[j]){
                sum+=mid-a[j];
            }
        if(sum>k){
            Max=mid;
        }
        else{
            Min=mid;
        }
    }
    printf("%lld\n",Min);
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000

 */