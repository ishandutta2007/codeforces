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

const int nax = 1000*1000+10,INF=1e9;
int n,m;
vector<bool>t[nax];
vi p[nax];
vector<bool>done[nax];

int check() {
	int w = INF;
	for(int i=1; i<=n; i++) {
		int act = 0;
		for(int j=1; j<=m+1; j++) {
			if(!t[i][j]&&t[i][j-1]) {
				w=min(w,act);
				act=0;
			}
			if(t[i][j]) act++;
		}
	}
	for(int i=1; i<=m; i++) {
		int act = 0;
		for(int j=1; j<=n+1; j++) {
			if(!t[j][i]&&t[j-1][i]) {
				w=min(w,act);
				act=0;
			}
			if(t[j][i]) act++;
		}
	}
	return w;
}

int main() {_
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		t[i].PB(0);
		for(int j=1; j<=m; j++) {
			char c;
			cin>>c;
			if(c=='X') t[i].PB(1);
			else t[i].PB(0);
		}
		t[i].PB(0);
	}
	for(int i=0; i<=m+1; i++) t[n+1].PB(0);
	for(int i=0; i<=m+1; i++) t[0].PB(0);
	p[0].resize(m+1);
	for(int i=1; i<=n; i++) {
		p[i].resize(m+1);
		for(int j=1; j<=m; j++) {
			p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1]+t[i][j];
		}
	}
	int W = (check()-1)/2;
	cout<<W<<"\n";
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(i>W&&j>W&&i+W<=n&&j+W<=m) {
				if(p[i+W][j+W]-p[i+W][j-W-1]-p[i-W-1][j+W]+p[i-W-1][j-W-1]==((2*W+1)*(2*W+1))) {
					cout<<"X";
				}
				else {
					cout<<".";
				}
			}
			else {
				cout<<".";
			}
		}
		cout<<"\n";
	}
	
}