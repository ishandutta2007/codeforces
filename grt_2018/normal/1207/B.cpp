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

int n,m;
bool a[51][51];
bool ok=1;
vector<pi>movee;
bool c[51][51];

int main() {_
	cin>>n>>m;
	for(int i=1; i<=n;i++) {
		for(int j=1; j<=m;j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=n;i++) {
		for(int j=1; j<=m;j++) {
			if(a[i][j]) {
				if(c[i][j]&&(i==n||j==m)) continue;
				if(i==n||j==m) ok=0;
				else {
					if(!(a[i][j+1]&&a[i+1][j]&&a[i+1][j+1])) {
						if(!c[i][j]) ok=0;
					}
					else {
						c[i][j] = c[i+1][j]=c[i][j+1]=c[i+1][j+1]=1;
						movee.PB({i,j});
					}
				}
			}
		}
	}
	if(!ok) cout<<"-1";
	else {
		cout<<movee.size()<<"\n";
		for(auto it: movee) {
			cout<<it.ST<<" "<<it.ND<<"\n";
		}
	}
}