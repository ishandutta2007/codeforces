#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int dp[2005][2005];
char f[2005][2005];
int n,k;
vector<P>cand;
int mx;
string ans = "";
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%s",&f[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int num = 0;
			if(i) num = max(num,dp[i-1][j]);
			if(j) num = max(num,dp[i][j-1]);
			num += (f[i][j] == 'a');
			dp[i][j] = num;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+j+1-dp[i][j] <= k){
				mx = max(mx,i+j);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+j+1-dp[i][j] <= k && mx == i+j){
				cand.pb(mp(i,j));
			}
		}
	}
	if(cand.size()) rep(e,mx+1) ans.pb('a');
	else{
	    cand.pb(mp(0,0));
	    ans.pb(f[0][0]);
	}
	for(int j=mx;j<2*n-2;j++){
		char ch = '1';
		for(int k=0;k<cand.size();k++){
			int x = cand[k].fi, y = cand[k].sc;
			if(x != n-1){
				if(ch == '1' || ch > f[x+1][y]) ch = f[x+1][y];
			}
			if(y != n-1){
				if(ch == '1' || ch > f[x][y+1]) ch = f[x][y+1];
			}
		}
	//	assert(ch != '1');
		ans.pb(ch);
		bool ok[4005]={};
		for(int k=0;k<cand.size();k++){
			int x = cand[k].fi, y = cand[k].sc;
			if(x != n-1){
				if(ch == f[x+1][y]) ok[x+1] = 1;//new_cand.pb(mp(x+1,y));
			}
			if(y != n-1){
				if(ch == f[x][y+1]) ok[x] = 1;//new_cand.pb(mp(x,y+1));
			}
		}
		cand.clear();
		for(int w=0;w<=j+1;w++) if(ok[w]) cand.pb(mp(w,j+1-w));
	}
	cout << ans << endl;
}