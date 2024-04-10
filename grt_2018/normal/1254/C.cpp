#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 1000+10;
int n;
vector<pair<ll,int> > g[2];

int main() {
	cin>>n;
	for(int i=3; i<=n; i++) {
		int x;
		cout<<"2 1 2 "<<i<<"\n";
		fflush(stdout);
		cin>>x;
		ll d;
		cout<<"1 1 2 "<<i<<"\n";
		fflush(stdout);
		cin>>d;
		if(x<0) g[0].PB({d,i});
		else g[1].PB({d,i});
	}
	sort(g[0].begin(),g[0].end());
	sort(g[1].begin(),g[1].end());
	vi ans = {0};
	int a = 1;
	for(int k : {0,1}) {
		vi v1 = {}, v2 = {};
		for(auto e:g[k]) {
			int x;
			if(e.ND==g[k].back().ND) continue;
			cout<<"2 "<<a<<" "<<g[k].back().ND<<" "<<e.ND<<"\n";
			fflush(stdout);
			cin>>x;
			if(x<0) v1.PB(e.ND);
			else v2.PB(e.ND);
		}
		if(g[k].size()>0) v1.PB(g[k].back().ND);
		reverse(v2.begin(),v2.end());
		ans.PB(a);
		for(auto x:v1) ans.PB(x);
		for(auto x:v2) ans.PB(x	);
		a = 2;
	}
	for(auto it:ans) cout<<it<<" ";
	fflush(stdout);
}