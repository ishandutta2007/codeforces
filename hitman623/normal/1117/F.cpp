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
int n,p,a[17][17],mask,freq[17],ans=hell;
int cost[1<<17],dp[1<<17];
bool iscrisp[1<<17];
bitset<1<<17> isadj[17][17];
string s;
void process_iscrisp(){
    rep(i,0,p){
        rep(j,i,p){
            if(i==j){
                int cur=0,f=0;
                rep(k,0,n){
                    if(s[k]-'a'==i){
                        f++;
                        if(f>1) isadj[i][j][(1<<p)-1-cur]=1;
                        cur=0;
                    }
                    else cur|=1<<(s[k]-'a');
                }
            }
            else{
                int cur=0,f1=0,f2=0;
                rep(k,0,n){
                    if(s[k]-'a'==i){
                        if(f2) isadj[i][j][(1<<p)-1-cur]=1;
                        f1=1;
                        f2=0;
                        cur=0;
                    }
                    else if(s[k]-'a'==j){
                        if(f1) isadj[i][j][(1<<p)-1-cur]=1;
                        f2=1;
                        f1=0;
                        cur=0;
                    }
                    else cur|=1<<(s[k]-'a');
                }
            }
            for(int k=(1<<p)-1;k>=0;k--){
                if((k>>i)&1 and (k>>j)&1){
                    rep(l,0,p){
                        if(l==i or l==j or (k>>l)&1);
                        else if(isadj[i][j][k^(1<<l)]) isadj[i][j][k]=1;
                    }          
                }
            }
        }
    }
    rep(i,0,1<<p){
        iscrisp[i]=1;
        vi v;
        rep(j,0,p){
            if((i>>j)&1){
                v.pb(j);
            }
        }
        for(auto x:v){
            for(auto y:v){
                if(isadj[x][y][i] and a[x][y]==0) iscrisp[i]=0;
            }
        }
    }
}
void solve(){
    cin>>n>>p>>s;
    for(auto i:s){
        freq[i-'a']++;
        mask|=1<<(i-'a');
    }
    rep(i,0,p){
        rep(j,0,p){
            cin>>a[i][j];
        }
    }
    process_iscrisp();
    rep(i,0,1<<p){
        rep(j,0,p){
            if((i>>j)&1) cost[i]+=freq[j];
        }
    }
    dp[mask]=1;
    for(int i=(1<<p)-1;i>=0;i--){        
        if(iscrisp[i]==0) continue;
        rep(j,0,p){
            if((i>>j)&1);
            else dp[i]|=dp[i^(1<<j)];
        }
        if(dp[i]) ans=min(ans,cost[i]);
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