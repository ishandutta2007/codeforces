#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
pii p[200005];
vector<int> v[200005];
LL cnt1[200005],cnt2[200005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear(),cnt1[i]=cnt2[i]=0;
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        v[x].pb(y);
        cnt2[y]++;
    }
    LL ans2=0;
    LL x=0,y=n;
    for(int i = 1;i<=n;i++){
        y-=cnt2[i];
        ans2+=x*y*cnt2[i];
        x+=cnt2[i];
    }
    x=0,y=n;
    for(int i = 1;i<=n;i++){
        y-=v[i].size();
        ans2+=x*y*v[i].size();
        x+=v[i].size();
    }
    LL ans=0;
    LL sub=0;
    LL l=0,r=n;
    for(int i = 1;i<=n;i++){
        for(auto it:v[i]){
            cnt2[it]--;
            r--;
            sub-=cnt1[it];
        }
        for(auto it:v[i]){
            ans+=l*r-sub-cnt1[it]*r-cnt2[it]*l+cnt1[it]*cnt2[it]*2;
        }
        for(auto it:v[i]){
            cnt1[it]++;
            l++;
            sub+=cnt2[it];
        }
    }
    printf("%lld\n",ans2-ans);
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
*/