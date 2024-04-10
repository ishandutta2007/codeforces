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
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[100005];
    for(int i = 0;i<m;i++){
        scanf("%d",&a[i]);
    }
    
    sort(a,a+m);
    vector<pair<int,pii> > e;
    for(int i = 0;i<m;i++){
        e.pb(mp((a[(i+1)%m]-a[i]+n-1)%n+1,mp(i,(i+1)%m)));
    }
    sort(e.begin(),e.end());
    LL cnt=m;
    LL sum=m;
    LL ans=min(n*1ll,2*m*1ll*m-m+sum);
    if(n!=m)ans=min(n*1ll-1,2*m*1ll*m-m+sum);
    for(auto it:e){
        sum+=it.x-1;
        cnt--;
        ans=min(ans,2*cnt*1ll*cnt-cnt+sum);
        if(it.x-1==(cnt)*2*2+1)        ans=min(ans,2*cnt*1ll*cnt-cnt+sum-1);
     //   printf("%d %d\n",it.y.x,it.y.y);
     //   printf("%lld %lld %lld\n",2*cnt*1ll*cnt-cnt+sum,cnt,sum);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/