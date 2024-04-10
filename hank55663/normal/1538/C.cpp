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
#define last Last
#define MXN 200005
const int mod=1e9+7;
void solve(){
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    LL ans=0;
    for(int i =0;i<n;i++){
        if(a[i]+a[i]<l)ans-=i;
        else{
            ans-=lower_bound(a,a+n,l-a[i])-a;
        }
     //   printf("%lld\n",ans);
    }
    for(int i = 0;i<n;i++){
        if(a[i]+a[i]<=r)ans+=i;
        else{
            ans+=upper_bound(a,a+n,r-a[i])-a;
        }
   //      printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/