#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int getCost(int l, int r, int x){
	if(x < l)
		return l-x;
	if(x > r)
		return x-r;
	return 0;
}

int l[5005], r[5005];
vector<int> pos;
ll dp[2][10005];

int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	pos.push_back(x);
	rep(i,0,n){
		scanf("%d%d", l+i, r+i);
		pos.push_back(l[i]);
		pos.push_back(r[i]);
	}
	sort(pos.begin(), pos.end());
	rep(i,0,pos.size())
		dp[0][i]=abs(x-pos[i]);
	bool read=1, write=0;
	rep(i,0,n){
		read^=1;
		write^=1;
		ll minCost=1000000000000000000LL;
		rep(j,0,pos.size()){
			if(j)
				minCost += pos[j]-pos[j-1];
			minCost=min(minCost, dp[read][j]);
			dp[write][j]=minCost+getCost(l[i], r[i], pos[j]);
		}
		minCost=1000000000000000000LL;
		rrep(j,pos.size(),0){
			if(j < pos.size()-1)
				minCost += pos[j+1]-pos[j];
			minCost=min(minCost, dp[read][j]);
			dp[write][j]=min(dp[write][j], minCost+getCost(l[i], r[i], pos[j]));
		}
	}
	ll ans=1000000000000000000LL;
	rep(j,0,pos.size())
		ans=min(ans, dp[write][j]);
	cout << ans << endl;
}