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

const int nax = 110, kax = 1000*1000+10,INF=1e9;
int n,m;
int dist[nax][nax];
int a[kax];
int ans = 1;
vi an;

int main() {_
	cin>>n;
	string s;
	for(int i=1; i<=n;i++) {
		cin>>s;
		for(int j=1; j<=n; j++) {
			if(s[j-1]=='0') dist[i][j] = INF;
			else dist[i][j] = 1;
		}
	}
	for(int k=1; k<=n;k++) {
		for(int i=1; i<=n;i++) {
			for(int j=1; j<=n; j++) {
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=1; i<=n;i++) dist[i][i] = 0;
	cin>>m;
	for(int i=1; i<=m;i++) cin>>a[i];
	int wsk = 1,last = 1;
	an.PB(a[1]);
	while(last<m) {
		while(wsk+1<=m&&dist[a[last]][a[wsk+1]]==wsk+1-last) {
			wsk++;
		}
		ans++;
		an.PB(a[wsk]);
		last = wsk;
	}
	cout<<ans<<"\n";
	for(auto it:an) {
		cout<<it<<" ";
	}
}