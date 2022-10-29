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
#define BLOCK		520
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,a[100005],cnt[100005],nxt[100005];
void solve(){
	cin>>n>>m;
	rep(i,1,n+1) cin>>a[i];
	for(int i=n;i>=1;i--){
		int r=min(n+1,(i/BLOCK+1)*BLOCK);
		if(i+a[i]>=r) nxt[i]=min(n+1,i+a[i]),cnt[i]=1;
		else nxt[i]=nxt[i+a[i]],cnt[i]=cnt[i+a[i]]+1;
	}
	while(m--){
		int type;
		cin>>type;
		if(type==0){
			int x,y;
			cin>>x>>y;
			a[x]=y;
			for(int i=x;i>=x/BLOCK*BLOCK;i--){
				int r=min(n+1,(i/BLOCK+1)*BLOCK);
				if(i+a[i]>=r) nxt[i]=i+a[i],cnt[i]=1;
				else nxt[i]=nxt[i+a[i]],cnt[i]=cnt[i+a[i]]+1;				
			}
		}
		else{
			int x,ans=0,last=0;
			cin>>x;
			while(x<=n){
				ans+=cnt[x];
				last=x;
				x=nxt[x];
			}
			while(last+a[last]<=n) last=last+a[last];
			cout<<last<<" "<<ans<<endl;
		}
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