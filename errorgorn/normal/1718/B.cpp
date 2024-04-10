//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int f[60];

int n;
int arr[105];
int cnt[60];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	f[0]=f[1]=1;
	rep(x,2,60) f[x]=f[x-1]+f[x-2];
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		
		int tot=0;
		rep(x,1,n+1) tot+=arr[x];
		
		int curr=-1;
		int num=0;
		while (num<tot){
			curr++;
			num+=f[curr];
		}
		
		if (tot!=num){
			cout<<"NO"<<endl;
			continue;
		}
		
		memset(cnt,0,sizeof(cnt));
		vector<int> v;
		rep(x,1,n+1){
			rep(y,60,0) if (arr[x]>=f[y]){
				if (arr[x]==f[y]) v.pub(y);
				else cnt[y]++;
				
				arr[x]-=f[y];
			}
		}
		
		cnt[1]--;
		sort(all(v));
		for (auto it:v){
			if (it>curr || cnt[it]==1){
				cnt[1]++;
				for (int y=2;y<it;y+=2) cnt[y]++;
			}
			else{
				cnt[it]++;
			}
		}
		
		
		//rep(y,1,curr+1) cout<<cnt[y]<<" "; cout<<endl;
		
		bool bad=false;
		rep(y,1,curr+1) if (cnt[y]!=1) bad=true;
		
		if (!bad) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}