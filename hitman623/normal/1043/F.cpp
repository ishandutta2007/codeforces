#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int lp[1000006];
void pre(int n){
    lp[1]=1; 
    rep(i,2,n+1){
        if(lp[i]==0){
            lp[i]=i;
            for(int j=2*i;j<=n;j+=i){                
                if(lp[j]==0) lp[j]=i; 
            } 
        } 
    }
}
int n;
vi val[300005];
vi a[300005];
int check[300005],g;
int dp[1<<8],w[1<<8];
void solve(){
    pre(300002);
    cin>>n;
    rep(i,1,n+1){
        int x;
        cin>>x;
        g=__gcd(g,x);
        if(x==1){
            cout<<1<<endl;
            return;
        }
        vi f;
        while(x!=1){
            int d=lp[x];
            f.pb(d);
            while(x%d==0) x/=d;
        }
        int m=sz(f);
        rep(j,1,1<<m){
            int cur=1;
            rep(k,0,m){
                if((j>>k)&1){
                    cur*=f[k];
                }
            }
            a[cur].pb(i);
        }
        val[i]=f;
    }
    if(g>1){
        cout<<-1<<endl;
        return;
    }
    rep(i,1,300001){
        int x=i;
        vi f;
        while(x!=1){
            int d=lp[x];
            f.pb(d);
            while(x%d==0) x/=d;
        }
        int m=sz(f);
        int ans=n;
        rep(j,0,1<<m){
            int cur=1;
            rep(k,0,m){
                if((j>>k)&1){
                    cur*=f[k];
                }
            }
            if(__builtin_popcount(j)%2) ans-=sz(a[cur]);
            else ans+=sz(a[cur]);
        }
        if(ans) check[i]=1;
    }
    int ans=hell;
    rep(i,1,n+1){
        int m=sz(val[i]);
        rep(j,0,1<<m){
            int cur=1;
            rep(k,0,m){
                if((j>>k)&1){
                    cur*=val[i][k];
                }
            }
            w[j]=cur;
        }
        memset(dp,1,sizeof dp);
        dp[0]=0;
        rep(j,0,1<<m){
            for(int k=j;k>0;k=j&(k-1)){
                if(check[w[k]]){
                    dp[j]=min(dp[j],dp[j^k]+1);
                }
            }
        }
        ans=min(ans,dp[(1<<m)-1]+1);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}