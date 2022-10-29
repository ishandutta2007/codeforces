#include <bits/stdc++.h>

#define int         long long
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
#define hell        1000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
string s;
int dp[10][10];
int ans[10][10];
int go(int x,int y){
    if(x>y) swap(x,y);
    if(ans[x][y]!=-2) return ans[x][y];
    rep(i,0,10){
        rep(j,0,10){
            dp[i][j]=hell;
        }
    }
    rep(i,0,10){
        dp[i][(i+x)%10]=0;
        dp[i][(i+y)%10]=0;
    }
    rep(k,0,10){
        rep(i,0,10){
            rep(j,0,10){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+1);
            }
        }
    }
    int res=0;
    rep(i,1,sz(s)){
        res+=dp[s[i-1]-'0'][s[i]-'0'];
    }
    if(res<hell) return ans[x][y]=res;
    else return ans[x][y]=-1;
}
void solve(){
    rep(i,0,10){
        rep(j,0,10){
            ans[i][j]=-2;
        }
    }    
    cin>>s;
    rep(x,0,10){
        rep(y,0,10){
            cout<<go(x,y)<<" ";
        }
        cout<<endl;
    }
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