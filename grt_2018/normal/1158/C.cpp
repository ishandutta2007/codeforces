#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 500*1000+10;
int t,n,nr,r;
vi V[nax];
int res[nax],p[nax];
pii S[nax];

void dfs(int x) {
	res[x]=nr--;
	for(auto nbh:V[x]) {
		dfs(nbh);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		nr = n+1; r=0;
		for(int i=1; i<=n+1; i++) {
			V[i].clear();
		}
		for(int i=1; i<=n;i++) {
			cin>>p[i];
			if(p[i]==-1) {
				V[i+1].PB(i);
				p[i] = i+1;
			}
			else {
				V[p[i]].PB(i);
			}
		}
		dfs(n+1);
		bool ok=1;
		S[r++] = {n+1,n+1};
		for(int i=n; i>=1;i--) {
			while(r>0&&S[r-1].ST<res[i]) {
				r--;
			}
			if(p[i]!=S[r-1].ND) {
				ok=0;
			}
			S[r++] = {res[i],i};
		}
		if(ok) {
			for(int i=1; i<=n;i++) {
				cout<<res[i]<<" ";
			}
		}
		else cout<<"-1";
		cout<<"\n";
	}
}