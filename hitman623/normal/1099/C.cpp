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
string s,ans;
bool dp[202][202];
int k;
void solve(){
    cin>>s>>k;
    dp[0][0]=1;
    rep(i,1,sz(s)+1){
        rep(j,0,k+1){
            if(s[i-1]=='?') dp[i][j]=(i>=2?dp[i-2][j]:0)|dp[i-1][j];
            else if(s[i-1]=='*'){
                dp[i][j]=(i>=2?dp[i-2][j]:0)|dp[i-1][j];
                rep(l,1,j+1) dp[i][j]|=dp[i-2][j-l];
            }
            else dp[i][j]=dp[i-1][j-1];
        }
    }
    if(dp[sz(s)][k]==0){
        cout<<"Impossible"<<endl;
        return;
    }
    int cur=sz(s);
    while(cur){
        if(s[cur-1]=='?'){
            if(cur>=2 and dp[cur-2][k]){
                cur-=2;
            }
            else if(dp[cur-1][k]){
                cur--;
            }
        }
        else if(s[cur-1]=='*'){
            if(cur>=2 and dp[cur-2][k]){
                cur-=2;
            }
            else if(dp[cur-1][k]){
                cur--;
            }
            else{
                rep(l,1,k+1){
                    if(dp[cur-2][k-l]){
                        rep(_,0,l){
                            ans+=s[cur-2];
                        }
                        cur-=2;
                        k-=l;
                        break;
                    }
                }
            }
        }
        else{
            ans+=s[cur-1];
            cur--;
            k--;
        }
    }
    reverse(all(ans));
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