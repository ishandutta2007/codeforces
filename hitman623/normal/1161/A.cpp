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
int n,k,ent[100005],ext[100005],ans;
void solve(){
	cin>>n>>k;
	rep(i,1,k+1){
		int x;
		cin>>x;
		if(!ent[x]) ent[x]=i;
		ext[x]=i;
	}
	rep(i,1,n+1){
		if(ent[i]==0){
			ans+=(i-1>0)+(i+1<=n)+1;
			continue;
		}
		if(i-1>0 and (!ext[i-1] or ext[i-1]<ent[i])) ans++;
		if(i+1<=n and (!ext[i+1] or ext[i+1]<ent[i])) ans++;
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