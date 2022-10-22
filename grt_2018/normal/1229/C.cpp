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

const int nax = 100*1000+10;
int n,m,q;
vi in[nax];
int out[nax];
ll ans;

int main() {_
	cin>>n>>m;
	for(int a,b,i=0; i<m; i++) {
		cin>>a>>b;
		if(a>b) swap(a,b);
		in[a].PB(b);
		out[b]++;
	}
	cin>>q;
	for(int i=1; i<=n; i++) {
		ans+=((ll)in[i].size()*out[i]);
	}
	cout<<ans<<"\n";
	for(int a,i=0; i<q; i++) {
		cin>>a;
		ans-=((ll)in[a].size()*out[a]);
		for(int it:in[a]) {
			//cout<<it<<"\n";
			ans-=(ll)in[it].size()*out[it];
			in[it].PB(a);
			out[it]--;
			ans+=(ll)in[it].size()*out[it];
		}
		out[a]+=(int)in[a].size();
		in[a].clear();
		cout<<ans<<"\n";
	}
}