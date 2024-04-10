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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,dp[1<<20],cnt[1<<20][22];
int f[22][22],freq[22],msb[1<<20];
void solve(){
    cin>>n;
    rep(i,0,n){
    	int x;
    	cin>>x;
    	x--;
    	rep(j,0,20) f[x][j]+=freq[j];
    	freq[x]++;
    }
    rep(i,0,1<<20){
    	rep(j,0,20){
    		if((i>>j)&1){
    			msb[i]=j;
    			break;
   			}
   		}
   	}
   	rep(i,1,1<<20){
   		rep(j,0,20){
   			if((i>>j)&1) continue;
   			cnt[i][j]=cnt[i^(1<<msb[i])][j]+f[j][msb[i]];
   		}
   	}
   	memset(dp,12,sizeof dp);
   	dp[0]=0;
    rep(i,0,1<<20){
    	rep(j,0,20){
    		if((i>>j)&1){
    			dp[i]=min(dp[i],dp[i^(1<<j)]+cnt[i^(1<<j)][j]);
    		}
    	}
    }
    cout<<dp[(1<<20)-1]<<endl;
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