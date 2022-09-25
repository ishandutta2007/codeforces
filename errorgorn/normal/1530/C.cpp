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
int arr[100005];
int brr[100005];

bool can(int i){
	vector<int> v1(arr,arr+n),v2(brr,brr+n);
	rep(x,0,i){
		v1.pub(100);
		v2.pub(0);
	}
	
	sort(all(v1)); reverse(all(v1));
	sort(all(v2)); reverse(all(v2));
	
	int num=(n+i)-(n+i)/4;
	int tot=0;
	rep(x,0,num) tot+=v1[x]-v2[x];
	return tot>=0;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		rep(x,0,n) cin>>brr[x];
		
		int lo=-1,hi=3*n+5,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (can(mi)) hi=mi;
			else lo=mi;
		}
		
		cout<<hi<<endl;
	}
}