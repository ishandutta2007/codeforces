// Super Idol
//    
//  
//    
//  105C
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

int n;
int arr[1005];
int brr[1005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		
		set<int> s;
		rep(x,1,n+1) s.insert(x);
		
		if (n==1){
			cout<<"-1"<<endl;
			continue;
		}
		
		rep(x,1,n-1){
			auto it=s.begin();
			if (*it==arr[x]) it=next(it);
			brr[x]=*it;
			s.erase(it);
		}
		
		brr[n-1]=*s.begin(); s.erase(s.begin());
		brr[n]=*s.begin(); s.erase(s.begin());
	
		if (brr[n-1]==arr[n-1] || brr[n]==arr[n]) swap(brr[n-1],brr[n]);
		
		rep(x,1,n+1) cout<<brr[x]<<" "; cout<<endl;
	}
	
}