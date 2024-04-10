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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    LL a[15];
    k++;
    LL val[15];
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
        val[i]=1;
        for(int j = 0;j<a[i];j++){
            val[i]=val[i]*10;
        }
       // printf("%lld\n",val[i]);
    }
    LL ans=0;
    for(int i = 0;i<n-1;i++){
        LL tot=min(k,(val[i+1]-val[i])/val[i]);
       // printf("%lld\n",tot);
        ans+=val[i]*tot;
        k-=tot;
    }
    ans+=k*val[n-1];
    printf("%lld\n",ans);
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/