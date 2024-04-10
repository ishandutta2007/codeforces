#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
int n;
vector<int>vi;
bitset<1300005>dp[55][35];
int main(){
	cin >> n;
	rep(i,2*n){
		int a; scanf("%d",&a);
		vi.pb(a);
	}
	sort(vi.begin(),vi.end());
	int ans = 5000000;
	vector<int>x,y;
	int ss = 0;
	for(int i=2;i<vi.size();i++) ss += vi[i];
	{
		int sum = 0;
		for(int j=2;j<2*n;j++) sum += vi[j];
		dp[1][0][0] = 1;
		for(int j=2;j<2*n;j++){
			for(int k=n-2;k>=0;k--){
				dp[j][k+1] |= dp[j-1][k] << vi[j];
				dp[j][k] |= dp[j-1][k];
			}
		}
		int S = 5000000; int id = -1;
		for(int j=0;j<=1300000;j++){
			if(dp[2*n-1][n-1][j] == 0) continue;
			if(S > max(j,ss-j)){
				S = max(j,ss-j);
				id = j;
			}
		}
		if(ans > S){
			ans = S;
			vector<int>p,q;
			int cur = n-1; int va = id;
			for(int j=2*n-1;j>=2;j--){
				if(cur > 0 && va >= vi[j] && dp[j-1][cur-1][va-vi[j]]){
					p.pb(vi[j]);
					cur--; va -= vi[j];
				}
				else q.pb(vi[j]);
			}
			assert(cur == 0 && va == 0);
			sort(p.begin(),p.end());
			sort(q.begin(),q.end(),greater<int>());
			x = p; y = q;
		}
	}
	cout << vi[0];
	rep(i,x.size()) cout << " " << x[i];
	cout << endl;
	rep(i,y.size()) cout << y[i] << " ";
	cout << vi[1] << endl;
	//cout << ans << endl;
}