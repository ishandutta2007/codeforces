#include <bits/stdc++.h>

#define ll          long long
#define pb          emplace_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define sqrt        320
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,deg[100005];
int val[100005],ans[100005];
vi a[100005],can[100005];
void solve(){
    scanf("%d",&n);
    rep(i,0,n){
        double p;
        scanf("%lf",&p);
        val[i]=p*100+0.5;
    }
    rep(i,0,n-1){
        int u,v;
        scanf("%d",&u);
        scanf("%d",&v);
        a[u].pb(v);
        a[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    rep(i,0,n){
        for(auto j:a[i]){
            if(deg[j]>=sqrt){
                can[i].pb(j);
                ans[j]+=val[i];
            }
        }
    }
    int sum1=0,sum2=0;
    rep(i,0,n){
        sum1+=(deg[i]-1)*val[i];
        for(auto j:a[i]){
            sum2+=val[i]*val[j];
        }
    }
    sum2/=2;
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        double _d;
        scanf("%d",&x);
        scanf("%lf",&_d);
        int d=_d*100+0.5;
        if(deg[x]<sqrt){
            for(auto i:a[x]){
                sum2+=val[i]*(d-val[x]);
            }
        }
        else sum2+=ans[x]*(d-val[x]);
        for(auto i:can[x]) ans[i]+=d-val[x];
        sum1+=(deg[x]-1)*(d-val[x]);
        val[x]=d;
        printf("%0.6lf\n",(sum1/100.0-sum2/10000.0+1));
    }
}

signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}