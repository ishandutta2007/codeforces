#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define fi first
#define se second

#define puf push_front
#define pof pop_front
#define pub push_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound

#define rep(x,s,e) for (int x=(s)-((s)>(e));x!=(e)-((s)>(e));((s)<(e))?x++:x--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=1000000007;

int n;
int arr[100005];
int pos[100005];
set<int> s;

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		rep(x,0,n) pos[arr[x]]=x;
		
		int l=pos[0],r=pos[0];
		int cnt=0;
		int ans=1;
		rep(x,0,n){
			while (!s.empty() && *s.begin()<x){
				ans=ans*cnt%MOD;
				cnt--;
				s.erase(s.begin());
			}
			
			if (l<=pos[x] && pos[x]<=r) continue;
			
			while (pos[x]<l) s.insert(arr[--l]),cnt++;
			while (r<pos[x]) s.insert(arr[++r]),cnt++;
			
			s.erase(s.begin());
			cnt--;
		}
		
		while (!s.empty()){
			ans=ans*cnt%MOD;
			cnt--;
			s.erase(s.begin());
		}
		
		cout<<ans<<endl;
	}
}