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
const int mod = 1e9+7;
void solve(){
    vector<int> a,b;
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x>0)a.pb(x);
        else b.pb(-x);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    a.pb(0);
    b.pb(0);
    LL ans=0;
    ans+=a[0]+b[0];
    ans+=min(a[0],b[0]);
    for(int i = k;i<a.size();i+=k)ans+=a[i]*2;
    for(int i = k;i<b.size();i+=k)ans+=b[i]*2;
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/