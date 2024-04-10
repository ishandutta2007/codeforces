// Problem: C. Parity Shuffle Sorting
// Contest: Codeforces - Codeforces Round #821 (Div. 2)
// URL: https://codeforces.com/contest/1733/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

int n;
int arr[100005];

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
		
		vector<int> a,b;
		rep(x,1,n+1){
			if (arr[1]%2==arr[x]%2) a.pub(x);
			else b.pub(x);
		}
		
		cout<<n-1<<endl;
		rep(x,sz(a)-1,0) cout<<a[x]<<" "<<a[x+1]<<endl;
		rep(x,0,sz(b)) cout<<a[0]<<" "<<b[x]<<endl;
	}
}