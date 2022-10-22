#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int n,m;
int a[51][51],b[51][51];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0; i<n;i++) {
		for(int j=0; j<m;j++) {
			cin>>a[i][j];
		}
	}
	for(int i=0; i<n;i++) {
		for(int j=0; j<m;j++) {
			cin>>b[i][j];
		}
	}
	for(int i=0; i<n;i++) {
		for(int j=0; j<m;j++) {
			int x =max(a[i][j],b[i][j]),y=min(a[i][j],b[i][j]);
			a[i][j]=y;
			b[i][j]=x;
		}
	}
	bool ok=1;
	for(int i=0; i<n;i++) {
		for(int j=0; j<m;j++) {
			if(i>0&&a[i][j]<=a[i-1][j]) {
				ok=0;
			}
			if(j>0&&a[i][j]<=a[i][j-1]) {
				ok=0;
			}
		}
	}
	for(int i=0; i<n;i++) {
		for(int j=0; j<m;j++) {
			if(i>0&&b[i][j]<=b[i-1][j]) {
				ok=0;
			}
			if(j>0&&b[i][j]<=b[i][j-1]) {
				ok=0;
			}
		}
	}
	if(ok) {
		cout<<"Possible";
	}
	else {
		cout<<"Impossible";
	}
}