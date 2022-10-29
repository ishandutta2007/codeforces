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
int n,a[200005];
vi divisors[200001];
void process_seive(int m){
	rep(i,1,m+1){
		for(int j=i;j<=m;j+=i){
			divisors[j].pb(i);
		}
	}
}
void solve(){
	process_seive(200000);
	cin>>n;
	rep(i,2,n+1){
		cin>>a[i];
		i++;
	}
	int cur=0;
	rep(i,1,n+1){
		bool done=0;
		for(auto d1:divisors[a[i+1]]){
			int d2=a[i+1]/d1;
			if((d1+d2)%2)continue;
			int z=(d2-d1)/2;
			if(z<0 or z*z-cur<=0) continue;
			if(done) a[i]=min(a[i],z*z-cur);
			else a[i]=z*z-cur;
			done=1;
		}
		if(done==0){
			cout<<"No"<<endl;
			return;
		}
		cur+=a[i];
		i++;
		cur+=a[i];
	}
	cout<<"Yes"<<endl;
	rep(i,1,n+1) cout<<a[i]<<" ";
	cout<<endl;
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