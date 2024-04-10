#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
static const double INF = 2147483647;
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005],b[100005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++)scanf("%d",&b[i]);
    sort(a,a+n);
    reverse(a,a+n);
    sort(b,b+n);
    reverse(b,b+n);
    int Max=4*n,Min=-1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int tota=n+mid;
        tota=tota-tota/4;
        int sum1=0,sum2=0;
        int totx=tota;
        int add=min(totx,mid);
        sum1+=add*100;
        totx-=add;
        for(int i = 0;i<totx;i++)sum1+=a[i];
        for(int i = 0;i<tota&&i<n;i++)sum2+=b[i];
        if(sum1>=sum2)Max=mid;
        else Min=mid;
    }
    printf("%d\n",Max);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}