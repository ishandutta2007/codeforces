#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int nax = 500*1000+10;
int q,n,k;
vector<pi>V[nax];
ll dp[nax][2];

void dfs(int x,int p) {
	for(auto nbh:V[x]) {
		if(nbh.ST!=p) dfs(nbh.ST,x);
	}
	if(V[x].size()==1&&p!=0) {
		dp[x][0] = dp[x][1] = 0;
	} else {
		vector<ll> val={};
		ll sum=0,s1=0,s2=0;
		for(auto nbh:V[x]) if(nbh.ST!=p) {
			sum+=dp[nbh.ST][1];
			val.PB(dp[nbh.ST][0]-dp[nbh.ST][1]+nbh.ND);
		}
		sort(val.begin(),val.end());
		reverse(val.begin(),val.end());
		for(int i=0; i<min((int)val.size(),k-1); i++) {
			s1+=max(val[i],(ll)0);
		}
		s2 = s1;
		if((int)val.size()>=k) s2+=max(val[k-1],(ll)0);
		dp[x][0] = s1+sum;
		dp[x][1] = s2+sum;
	}
}

int main() {_
	cin>>q;
	while(q--) {
		cin>>n>>k;
		for(int i=1; i<=n; i++) V[i].clear();
		for(int a,b,w,i=1; i<n; i++) {
			cin>>a>>b>>w;
			V[a].PB({b,w});
			V[b].PB({a,w});
		}
		dfs(1,0);
		cout<<dp[1][1]<<"\n";
	}
}