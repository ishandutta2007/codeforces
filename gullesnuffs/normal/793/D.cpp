#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int c[85][85];
int n;
int dp[82][82][82][82];

int rec(int pos, int l, int r, int k){
	if(!k)
		return 0;
	if(dp[pos][l+1][r][k] != -1)
		return dp[pos][l+1][r][k];
	int ans = 1000000000;
	rep(i,l+1,r){
		if(c[pos][i] == 1000000000)
			continue;
		if(i == pos)
			continue;
		int newl = l;
		int newr = r;
		if(i < pos){
			newr = pos;
		}
		else{
			newl = pos;
		}
		ans = min(ans, c[pos][i]+rec(i, newl, newr, k-1));
		/*bool turned = false;
		if(lastPos == -1){
		}
		else{
			if(i < pos && i < lastPos){
				if(pos < lastPos && canContinue){
				}
				else{
					continue;
				}
			}
			else if(i > pos && i > lastPos){
				if(pos > lastPos && canContinue){
				}
				else{
					continue;
				}
			}
			else{
				turned = true;
			}
		}*/
	}
	dp[pos][l+1][r][k] = ans;
	return ans;
}

int main(){
	rep(i,0,82)
	rep(j,0,82)
	rep(l,0,82)
	rep(m,0,82)
		dp[i][j][l][m]=-1;
	ios::sync_with_stdio(0);
	int k;
	cin >> n >> k;
	/*if(k > n){
		cout << "-1" << endl;
		return 0;
	}*/
	rep(i,0,n)
	rep(j,0,n)
		c[i][j] = 1000000000;
	int m;
	cin >> m;
	rep(i,0,m){
		int u, v, C;
		cin >> u >> v >> C;
		--u;--v;
		c[u][v] = min(c[u][v], C);
	}
	int ans = 1000000000;
	rep(s,0,n){
		ans=min(ans, rec(s, -1, n, k-1));
	}
	if(ans >= 1000000000)
		cout << "-1" << endl;
	else
		cout << ans << endl;
}