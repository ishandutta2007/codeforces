//
//
//
//

#include <bits/stdc++.h>
using namespace std;

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
int arr[505];
int memo[505][505][505];
int memo2[505][505][505];

int dp(int pos1,int pos2,int extra);
int dp2(int pos1,int pos2,int extra);

int dp(int pos1,int pos2,int extra){
	if (memo[pos1][pos2][extra-pos2]!=-1) return memo[pos1][pos2][extra-pos2];
	
	int res=0;
	
	if (pos1<n){
		res=dp(pos1+1,pos2,extra);
		int l=max(pos1,pos2)+1,r=min(extra+pos1-pos2+1,n);
		if (l<=r) res=max(res,dp2(pos1+1,l,extra+pos1-pos2+2));
	}
	
	//cout<<pos1<<" "<<pos2<<" "<<extra<<" "<<res+arr[pos2]<<endl;
	return memo[pos1][pos2][extra-pos2]=res+arr[pos2];
}

int dp2(int pos1,int pos2,int extra){
	if (memo2[pos1][pos2][extra-pos2]!=-1) return memo2[pos1][pos2][extra-pos2];
	
	if (pos2==min(extra-1,n)) return memo2[pos1][pos2][extra-pos2]=dp(pos1,pos2,extra);
	else return memo2[pos1][pos2][extra-pos2]=max(dp(pos1,pos2,extra),dp2(pos1,pos2+1,extra));
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	memset(memo,-1,sizeof(memo));
	memset(memo2,-1,sizeof(memo2));
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	cout<<max(dp(1,1,3),dp(1,2,3))<<endl;
}