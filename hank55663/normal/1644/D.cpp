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
int r[200005],c[200005];
const int mod=998244353;
void solve(){
    int n,m,k,q;
    scanf("%d %d %d %d",&n,&m,&k,&q);
    vector<pii> v;
    for(int i = 0;i<q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v.pb(mp(x,y));
    }
    reverse(v.begin(),v.end());
    fill(r,r+n+1,0);
    fill(c,c+m+1,0);
    LL ans=1;
    LL cntr=0,cntc=0;
    for(auto it:v){
        if(!r[it.x]||!c[it.y]){
            ans=ans*k%mod;
        }
        if(!r[it.x]){
            cntr++;
            r[it.x]=1;
        }
        if(!c[it.y]){
            cntc++;
            c[it.y]=1;
        }
        if(cntr==n||cntc==m)break;
    }
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