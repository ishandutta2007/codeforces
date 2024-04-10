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

struct Point {
	int x,y;
};

ll det(Point a,Point b) {
	return (ll)a.x*b.y-(ll)b.x*a.y;
}

ll dist(Point a) {
	return (ll)(a.x*a.x)+(ll)(a.y*a.y);
}

const int nax = 100*1000+10;
int n;
Point p[nax];


int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>p[i].x>>p[i].y;
	}
	if(n&1) {
		cout<<"NO";
		return 0;
	}
	p[n+1] = p[1];
	bool ok = 1;
	for(int i=1; i<=n/2; i++) {
		Point p1 = {p[i+1].x-p[i].x,p[i+1].y-p[i].y};
		Point p2 = {p[i+n/2+1].x-p[i+n/2].x,p[i+n/2+1].y-p[i+n/2].y};
		if(det(p1,p2)!=0||dist(p1)!=dist(p2)) {
			ok=0;
		}
	}
	if(ok) cout<<"YES";
	else cout<<"NO";
	
}