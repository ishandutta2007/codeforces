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
#define double long double
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    int loc[100005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        loc[a[i]]=i;
    }
    LL ans=1;
    const int mod=1e9+7;
    int l=loc[0],r=loc[0];
    for(int i = 1;i<n;i++){
        if(loc[i]>=l&&loc[i]<=r){
            ans=ans*(r-l+1-i);
            ans%=mod;
        }
        else{
            r=max(r,loc[i]);
            l=min(l,loc[i]);
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/