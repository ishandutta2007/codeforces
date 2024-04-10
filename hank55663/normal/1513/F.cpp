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
const int mod=1e9+7;
void solve(){
    int n;
    int a[200005];
    int b[200005];
    scanf("%d",&n);
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++)scanf("%d",&b[i]);
    LL ans=0;
    vector<pair<pii,int> > v;
    for(int i = 0;i<n;i++){
        ans+=abs(a[i]-b[i]);
        if(a[i]>b[i])v.pb(mp(mp(b[i],a[i]),0));
        if(a[i]<b[i])v.pb(mp(mp(a[i],b[i]),1));
    }
    sort(v.begin(),v.end());
    int Max[2]={0,0};//,Max2=0;
    int res=0;
    for(auto it:v){
        Max[it.y]=max(Max[it.y],it.x.y);
        res=max(res,min(Max[it.y^1],it.x.y)-it.x.x);
    }
    ans-=2*res;
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}