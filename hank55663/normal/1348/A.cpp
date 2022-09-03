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
#define MAXN 205
#define N 262144
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL a[30];
        int n;
        scanf("%d",&n);
        a[0]=2;
        for(int i = 1;i<n;i++)a[i]=a[i-1]<<1;
        LL sum1=0,sum2=0;
        for(int i = 0;i<n/2-1;i++)sum1+=a[i];
        for(int i =n/2-1;i<n-1;i++)sum2+=a[i];
        sum1+=a[n-1];
        printf("%lld\n",sum1-sum2);
    }
}