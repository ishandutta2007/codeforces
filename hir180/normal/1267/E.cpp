#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
typedef pair<int,int> P;
typedef long long ll;
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define INF 1000000000
int n,m,a[105][105];
int main(){
	cin >> m >> n;
	repn(i,n){
		repn(j,m) cin >> a[i][j];
	}
	int cnt = INF;
	vector<int>pos;
	repn(k,m-1){
		int sum = 0;
		vector<P>vec;
		repn(i,n){
			sum += a[i][m]-a[i][k];
			vec.pb(mp(a[i][m]-a[i][k],i));
		}
		sort(vec.begin(),vec.end(),greater<P>());
		int id = 0;
		vector<int>ers;
		while(sum > 0){
			sum -= vec[id].fi;
			ers.pb(vec[id++].sc);
		}
		if(cnt > id){
			cnt = id;
			pos = ers;
		}
	}
	assert(pos.size() == cnt);
	cout << cnt << endl;
	rep(i,cnt) cout << pos[i] << endl;
}