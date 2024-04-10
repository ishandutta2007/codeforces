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
using namespace std;
#define MXN 100005
void solve(){
    int n,m;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    LL sum=0;
    for(int i = 1;i<n;i++){
        sum+=abs(a[i]-a[i-1]);
    }
    LL ans=sum;
    for(int i = 1;i<n-1;i++){
        ans=min(ans,sum-abs(a[i]-a[i-1])-abs(a[i]-a[i+1])+abs(a[i+1]-a[i-1]));
    }
    ans=min(ans,sum-abs(a[0]-a[1]));
    ans=min(ans,sum-abs(a[n-1]-a[n-2]));
    printf("%lld\n",ans);

}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
       solve();
    }
}
/*
*/