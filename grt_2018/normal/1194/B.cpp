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

const int nax = 500*100+10;
int q,n,m;
int row[nax],col[nax];
vector<bool> t[nax];

int main() {_
	cin>>q;
	while(q--) {
		cin>>n>>m;
		for(int i=0; i<n;i++) {row[i]=0;t[i].clear(); t[i].resize(m);}
		for(int i=0; i<m;i++) col[i]=0;
		for(int i=0; i<n;i++) {
			for(int j=0; j<m;j++) {
				char c; cin>>c;
				if(c=='.') t[i][j] = 1;
				else t[i][j] = 0;
				row[i]+=t[i][j]; col[j]+=t[i][j];
			}
		}
		int ans = n+m-1;
		for(int i=0; i<n;i++) {
			for(int j=0; j<m;j++) {
				ans=min(ans,col[j]+row[i]-t[i][j]);
			}
		}
		cout<<ans<<"\n";
	}
	
}